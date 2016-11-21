#ifndef RENDERER_HPP
#define RENDERER_HPP

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class RendererInterface {
            public:
                virtual void initialize()=0;
                virtual void destroy()=0;
                virtual void resize(int w, int h)=0;
            };
        }
    }
}

#endif 

