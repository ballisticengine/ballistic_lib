#include "types/common.hpp"
#include "types/graphics/materials/SimpleColorMaterial.hpp"
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
                glDisable(GL_TEXTURE_2D);
                glEnable(GL_NORMALIZE);
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

                glShadeModel(GL_SMOOTH);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_BLEND);
                glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();

                glFrustum(-2, 2, -2, 2, 2, 200);

            }

            void GLRenderer::destroy() {

            }

            void GLRenderer::resize(int w, int h) {
                glViewport(0, 0, w, h);
            }

            void GLRenderer::start() {

                glClearColor(0, 0, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef(0, 0, -3);

                glPointSize(2);

                glColor4f(1, 0, 0, 1);
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

                //glGenVertexArrays(1, &vboData->vaoId);
            
                
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
                
                using Ballistic::Core::Types::Graphics::Color;
                using Ballistic::Core::Types::Graphics::Materials::SimpleColorMaterial;
                
                
                
                if (mtl.getType() == "SimpleColor") {
                    SimpleColorMaterial *scm = (SimpleColorMaterial *) mtl.getMaterialData();
                    
//                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//                glBufferSubData(GL_ARRAY_BUFFER,
//                        vSize,
//                        vSize,
//                        tmpNorms);
                    
                    
                    //https://www.opengl.org/discussion_boards/showthread.php/183319-add-color-to-VBOs-best-practices

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
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glVbo->eId);

                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);

                glVertexPointer(3, GL_FLOAT, 0, (char *) 0);

                glNormalPointer(GL_FLOAT, 0, BUFFER_OFFSET(glVbo->nOffset));
                glDrawElements(GL_TRIANGLES, m->n_triangles * 3, GL_UNSIGNED_SHORT, 0);


                glDisableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);

                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }
            
            

        }
    }
}