#include "BeginFrameTask.hpp"
#include "../RenderingPipeline.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

             void BeginFrameTask::run(RenderingPipeline *p) {
                 p->getRenderer()->start();
            }
        }
    }
}



