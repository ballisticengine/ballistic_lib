#ifndef BEGINFRAMETASK_HPP
#define BEGINFRAMETASK_HPP

#include "../RenderingTask.hpp"
#include "../RenderingPipeline.hpp"
#include "../../renderers/RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            class BeginFrameTask : public RenderingTask {
            protected:
               virtual void run(RenderingPipeline *renderer);
            public:
                
            };
        }
    }
}



#endif 

