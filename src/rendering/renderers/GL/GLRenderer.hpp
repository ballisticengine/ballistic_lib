#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class GLRenderer : public RendererInterface {
            protected:
                void setUpShaders();
            public:
                virtual void initialize();
                virtual void destroy();
                virtual void resize(int w, int h);
                virtual void start();
                virtual void end();
                virtual Vbo * makeVbo(const Mesh &m,  Material &mtl);
                virtual void renderVbo(Vbo * vbo);
          
            };
        }
    }
}

#endif 

