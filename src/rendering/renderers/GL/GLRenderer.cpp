#include "types/common.hpp"
#include "GLRenderer.hpp"
#include "GLVbo.hpp"
#include <iostream>

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

            void *GLRenderer::makeMeshVbo(const Mesh &m) {

                GLfloat *tmpVerts = new GLfloat[m.n_vertices * 3];
                GLushort *tmpInds = new GLushort[m.n_triangles * 3];

                size_t vn = 0;
                for (size_t i = 0; i < m.n_vertices; i++) {
                    tmpVerts[vn] = m.vertices[i].x;
                    vn++;
                    tmpVerts[vn] = m.vertices[i].y;
                    vn++;
                    tmpVerts[vn] = m.vertices[i].z;
                    vn++;

                }

                size_t n = 0;
                for (size_t i = 0; i < m.n_triangles; i++) {
                    for (size_t x = 0; x < 3; x++) {
                        tmpInds[n] = m.triangles[i].indices[x];
                        n++;
                    }

                }

                GLVbo *vbo = new GLVbo();
                vbo->vId;

                glGenBuffers(1, &vbo->vId);

                glBindBuffer(GL_ARRAY_BUFFER, vbo->vId);

                glBufferData(GL_ARRAY_BUFFER, m.n_vertices * sizeof (GLfloat)*3, tmpVerts, GL_STATIC_DRAW);

                glGenBuffers(1, &vbo->eId);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo->eId);

                glBufferData(GL_ELEMENT_ARRAY_BUFFER, m.n_triangles * sizeof (GLushort)*3, tmpInds, GL_STATIC_DRAW);

                return vbo;

            }

            void GLRenderer::renderVbo(void* vbo) {

                GLVbo *glVbo = (GLVbo *) vbo;



                glBindBuffer(GL_ARRAY_BUFFER, glVbo->vId);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glVbo->eId);

                glEnableClientState(GL_VERTEX_ARRAY);

                glVertexPointer(3, GL_FLOAT, 0, (char *) 0);

                glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
                //                glDrawArrays(GL_POINTS, 0, 3);

                glDisableClientState(GL_VERTEX_ARRAY);

                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }
        }
    }
}