#include "types/common.hpp"
#include "types/graphics/materials/SimpleColorMaterial.hpp"
#include "types/graphics/materials/TextureMaterial.hpp"
#include "types/graphics/Color.hpp"
#include "GLRenderer.hpp"
#include "GLVbo.hpp"
#include <iostream>
#include "glsl/shaders.hpp"

using namespace std;
#define BUFFER_OFFSET(i) ((void*)(i))


//http://stackoverflow.com/questions/15548776/rendering-engine-design-abstracting-away-api-specific-code-for-resources
// http://www.songho.ca/opengl/gl_vbo.html
namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            void GLRenderer::initialize() {
                this->resize(800, 600);
                glewInit();

                glCullFace(GL_FRONT);
                glDisable(GL_LIGHTING);
                glFrontFace(GL_CCW);
                glEnable(GL_CULL_FACE);
                glEnable(GL_DEPTH_TEST);
                glEnable(GL_TEXTURE_2D);
                glEnable(GL_NORMALIZE);
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

                glShadeModel(GL_SMOOTH);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_BLEND);
                glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();

                glFrustum(-2, 2, -2, 2, 2, 200);

                setUpShaders();

            }

            void GLRenderer::destroy() {

            }

            void GLRenderer::setUpShaders() {
                GLhandleARB
                vhandle = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB),
                        fhandle = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);

                const char
                *vtext = GLSL_GENERIC_VERT,
                        *ftext = GLSL_GENERIC_FRAG;
                glShaderSourceARB(vhandle, 1, &vtext, 0);
                glShaderSourceARB(fhandle, 1, &ftext, 0);

                //                delete vtext;
                //                delete ftext;

                glCompileShaderARB(vhandle);
                glCompileShaderARB(fhandle);
                GLhandleARB p;
                p = glCreateProgramObjectARB();
                glAttachObjectARB(p, vhandle);
                glAttachObjectARB(p, fhandle);
                glLinkProgramARB(p);

                GLint vcompiled, fcompiled, linked;

                glGetProgramiv(p, GL_LINK_STATUS, &linked);


                glGetProgramiv(p, GL_LINK_STATUS, &linked);

                glGetObjectParameterivARB(vhandle, GL_COMPILE_STATUS, &vcompiled);
                glGetObjectParameterivARB(vhandle, GL_COMPILE_STATUS, &fcompiled);


                cout << "Status:" << vcompiled << ", " << fcompiled <<
                        ", " << linked << endl;

                glUseProgram(p);

            }

            void GLRenderer::resize(int w, int h) {
                glViewport(0, 0, w, h);
            }

            void GLRenderer::start() {

                glClearColor(0, 0, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef(0, 0, -5);

                //glPointSize(1);

                //glColor4f(1, 0, 0, 1);
            }

            void GLRenderer::end() {

                glFlush();

            }

            Vbo *GLRenderer::makeVbo(const Mesh &m, Material &mtl) {

                GLfloat *tmpVerts = new GLfloat[m.n_vertices * 3];
                GLfloat *tmpNorms = new GLfloat[m.n_vertices * 3];

                GLushort *tmpInds = new GLushort[m.n_triangles * 3];

                size_t vn = 0;
                for (size_t i = 0; i < m.n_vertices; i++) {
                    tmpNorms[vn] = m.normals[i].x;
                    tmpVerts[vn] = m.vertices[i].x;
                    vn++;
                    tmpNorms[vn] = m.normals[i].y;
                    tmpVerts[vn] = m.vertices[i].y;
                    vn++;
                    tmpNorms[vn] = m.normals[i].z;
                    tmpVerts[vn] = m.vertices[i].z;
                    vn++;

                }


                size_t n = 0;
                size_t nn = 0;
                for (size_t i = 0; i < m.n_triangles; i++) {
                    for (size_t x = 0; x < 3; x++) {
                        tmpInds[n] = m.triangles[i].indices[x];

                        n++;
                    }


                }

                GLVbo *vboData = new GLVbo();
                Vbo *vbo = new Vbo(&m, 0, vboData);


                vboData->vId;



                glGenBuffers(1, &vboData->vId);

                glBindBuffer(GL_ARRAY_BUFFER, vboData->vId);

                GLuint vSize = m.n_vertices * sizeof (GLfloat)*3;
                glBufferData(GL_ARRAY_BUFFER, vSize, tmpVerts, GL_STATIC_DRAW);

                glGenBuffers(1, &vboData->eId);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboData->eId);



                glBufferData(GL_ELEMENT_ARRAY_BUFFER, m.n_triangles * sizeof (GLushort)*3, tmpInds, GL_STATIC_DRAW);
                glBufferSubData(GL_ARRAY_BUFFER,
                        vSize,
                        vSize,
                        tmpNorms);

                vboData->nOffset = vSize;

                using namespace Ballistic::Core::Types::Graphics;
                using namespace Ballistic::Core::Types::Graphics::Materials;


                vboData->uvId = 0;
                if (mtl.getType() == "SimpleColor") {
                    SimpleColorMaterial *scm = (SimpleColorMaterial *) mtl.getMaterialData();

                    //                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
                    //                glBufferSubData(GL_ARRAY_BUFFER,
                    //                        vSize,
                    //                        vSize,
                    //                        tmpNorms);


                    //https://www.opengl.org/discussion_boards/showthread.php/183319-add-color-to-VBOs-best-practices

                } else if (mtl.getType() == "Texture") {
                    TextureMaterial *tm = (TextureMaterial *) mtl.getMaterialData();
                    UVMap *uvMap = tm->getUVMap();
                    glGenBuffers(1, &vboData->uvId);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboData->uvId);

                    size_t vn = 0;
                    GLfloat *tmpUVS = new GLfloat[uvMap->count * 2];
                    GLushort *tmpUvInds = new GLushort[uvMap->count * 3];

                    for (size_t i = 0; i < uvMap->count; i++) {
                        tmpUVS[vn++] = uvMap->uvs[i].x;
                        tmpUVS[vn++] = uvMap->uvs[i].y;

                    }
                    for (size_t i = 0; i < uvMap->count * 3; i++) {
                        tmpUvInds[i] = uvMap->triangles->indices[i];
                    }
                    vboData->uvOffset = vboData->nOffset + vSize;
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvMap->count * sizeof (GLushort) * 3, tmpUvInds, GL_STATIC_DRAW);
                    glBufferSubData(GL_ARRAY_BUFFER,
                            vboData->uvOffset,
                            uvMap->count * 2,
                            tmpUVS);

                }



                delete tmpInds;
                delete tmpVerts;
                delete tmpNorms;

                return vbo;

            }

            void GLRenderer::renderVbo(Vbo* vbo) {

                GLVbo *glVbo = (GLVbo *) vbo->rendererData;
                const Mesh *m = vbo->mesh;

                glBindBuffer(GL_ARRAY_BUFFER, glVbo->vId);

                if (glVbo->uvId) {
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glVbo->uvId);
                    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                    glTexCoordPointer(2, GL_FLOAT, 0, 0);
                }
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);


                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glVbo->eId);

                glVertexPointer(3, GL_FLOAT, 0, (char *) 0);
                glNormalPointer(GL_FLOAT, 0, BUFFER_OFFSET(glVbo->nOffset));
                glDrawElements(GL_TRIANGLES, m->n_triangles * 3, GL_UNSIGNED_SHORT, 0);


                glDisableClientState(GL_VERTEX_ARRAY);
                glDisableClientState(GL_NORMAL_ARRAY);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);

            }

            void GLRenderer::setupTexture(Ballistic::Core::Types::Graphics::Texture *texture) {
                GLuint texId;
                glGenTextures(1, &texId);
                this->textureMap[texture] = texId;
                glBindTexture(GL_TEXTURE_2D, texId);

                glTexStorage2D(GL_TEXTURE_2D, 8, GL_RGBA, texture->width, texture->height);

                glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_LINEAR_MIPMAP_LINEAR);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

                glTexImage2D(GL_TEXTURE_2D, 0, 4, texture->width, texture->height, 0, GL_RGBA,
                        GL_UNSIGNED_BYTE, (GLvoid *) texture->pixels);

                glGenerateMipmap(GL_TEXTURE_2D);
            }
        }
    }
}
