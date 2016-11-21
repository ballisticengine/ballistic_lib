#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include "../RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class RendererGL : public RendererInterface {
            public:
                virtual void initialize();
                virtual void destroy();
            };
        }
    }
}

#endif 

