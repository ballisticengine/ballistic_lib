#include "GLRenderer.hpp"
//http://stackoverflow.com/questions/15548776/rendering-engine-design-abstracting-away-api-specific-code-for-resources
namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            void GLRenderer::initialize() {
                this->resize(800, 600);
                glewInit();
                glCullFace(GL_FRONT);
                glFrontFace(GL_CW);
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

                glFrustum(-2,2,-2,2,2,5000);
            }

            void GLRenderer::destroy() {

            }

            void GLRenderer::resize(int w, int h) {
                glViewport(0, 0, w, h);
            }

            void GLRenderer::start() {
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                glClearColor(0.5, 0.5, 0.5, 1);
                glClear(GL_COLOR_BUFFER_BIT);
            }

            void GLRenderer::end() {
                glFlush();
            }
        }
    }
}