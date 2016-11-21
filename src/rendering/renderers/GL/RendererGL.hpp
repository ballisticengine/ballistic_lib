#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include "../Renderer.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class RendererGL : public Renderer {
            public:
                virtual void initialize();
                virtual void destroy();
            };
        }
    }
}

#endif 

