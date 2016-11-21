#ifndef RENDERINGPIPELINE_HPP
#define RENDERINGPIPELINE_HPP

#include "pipeline/Pipeline.hpp"
#include "../renderers/RendererInterface.hpp"

using Ballistic::Rendering::Renderers::RendererInterface;

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            class RenderingPipeline : public Ballistic::Core::Pipeline::Pipeline {
            protected:
                virtual void initialize();
                virtual void destroy();
                RendererInterface *renderer;
                
            public:
                RenderingPipeline(RendererInterface *renderer);
                RendererInterface* getRenderer();

            };
        }
    }
}



#endif

