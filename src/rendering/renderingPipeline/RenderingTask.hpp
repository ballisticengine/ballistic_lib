#ifndef RENDERINGTASK_HPP
#define RENDERINGTASK_HPP

#include "pipeline/Task.hpp"
#include "RenderingPipeline.hpp"
#include "../renderers/RendererInterface.hpp"

using Ballistic::Rendering::Renderers::RendererInterface;

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            class RenderingTask : public Ballistic::Core::Pipeline::Task {
            protected:
                virtual void run(void *p);
                virtual void run(RenderingPipeline *renderer)=0; //TODO: pass RenderingPipeline here
            public:
                
            };

        }
    }
}


#endif 

