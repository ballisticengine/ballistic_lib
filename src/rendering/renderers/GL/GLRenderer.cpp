#include "types/common.hpp"
#include "GLRenderer.hpp"
#include "GLVbo.hpp"

//http://stackoverflow.com/questions/15548776/rendering-engine-design-abstracting-away-api-specific-code-for-resources
// http://www.songho.ca/opengl/gl_vbo.html
namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            void GLRenderer::initialize() {
                glewInit();
                this->resize(800, 600);

//                glCullFace(GL_FRONT);
//                glFrontFace(GL_CW);
//                glEnable(GL_CULL_FACE);
//                glEnable(GL_DEPTH_TEST);
//                glEnable(GL_TEXTURE_2D);
//                glEnable(GL_NORMALIZE);
//                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

                glShadeModel(GL_SMOOTH);
//                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//                glEnable(GL_BLEND);
                glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();

                glFrustum(-2, 2, -2, 2, 2, 5000);
//                 glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
            }

            void GLRenderer::destroy() {

            }

            void GLRenderer::resize(int w, int h) {
                glViewport(0, 0, w, h);
            }

            void GLRenderer::start() {
                
                glClearColor(0, 0, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glTranslatef(0,0,-7);
                glColor3f(1,0,0);
            }

            void GLRenderer::end() {
                glFlush();
            }

            void *GLRenderer::makeMeshVbo(const Mesh &m) {

                 glEnableClientState(GL_VERTEX_ARRAY);
                using Ballistic::Core::Types::scalar_t;
                GLdouble **tmpVerts = new GLdouble*[m.n_vertices];
                GLuint *tmpInds = new GLuint[m.n_triangles*3];

                for (size_t i = 0; i < m.n_vertices; i++) {
                    tmpVerts[i] = new GLdouble[3];

                    tmpVerts[i][0] = m.vertices[i].x;
                    tmpVerts[i][1] = m.vertices[i].y;
                    tmpVerts[i][2] = m.vertices[i].z;
                }
                
                size_t n =0;
                for(size_t i=0; i<m.n_triangles; i++) {
                    for(size_t x=0; x<3; x++) {
                        tmpInds[n] = m.triangles[i].indices[x];
                        n++;
                    }
                    
                }
                
                glewInit();

                GLVbo *vbo = new GLVbo();
                vbo->vId;
                
                glGenBuffers(1, &vbo->vId);
                
                glBindBuffer(GL_ARRAY_BUFFER, vbo->vId);

                glBufferData(GL_ARRAY_BUFFER, m.n_vertices * sizeof (GLdouble)*3, tmpVerts, GL_STATIC_DRAW);

                 glGenBuffers(1, &vbo->eId);
                 
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo->eId);

                glBufferData(GL_ELEMENT_ARRAY_BUFFER_ARB, m.n_triangles * sizeof (unsigned int)*3, tmpInds, GL_STATIC_DRAW);

                 glDisableClientState(GL_VERTEX_ARRAY); 
                return vbo;

            }

            void GLRenderer::renderVbo(void* vbo) {
                GLVbo *glVbo = (GLVbo *) vbo;

              

                glBindBuffer(GL_ARRAY_BUFFER, glVbo->vId); 
                
                  
                glEnableClientState(GL_VERTEX_ARRAY);
                glVertexPointer(3, GL_DOUBLE, sizeof(GLdouble), 0);  
                
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glVbo->eId);
                glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
                
                glDisableClientState(GL_VERTEX_ARRAY); 
                
                glBindBufferARB(GL_ARRAY_BUFFER, 0);
                glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER, 0);
            }
        }
    }
}