#include "EndFrameTask.hpp"
#include "../RenderingPipeline.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            void EndFrameTask::run(RenderingPipeline *p) {
                p->getRenderer()->end();
            }
        }
    }
}
