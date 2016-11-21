#ifndef ENDFRAMETASK_HPP
#define ENDFRAMETASK_HPP

#include "../RenderingTask.hpp"
#include "../../renderers/RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            class EndFrameTask : public RenderingTask {
            protected:
                virtual void run(RenderingPipeline *p);
            };

        }
    }
}

#endif 

