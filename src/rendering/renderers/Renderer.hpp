#ifndef RENDERER_HPP
#define RENDERER_HPP

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class Renderer {
            public:
                virtual void initialize()=0;
                virtual void destroy()=0;
            };
        }
    }
}

#endif 

