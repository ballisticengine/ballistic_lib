#include "RenderingTask.hpp"

#include "RenderingPipeline.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {
            void RenderingTask::run(void *p) {
                 this->run(((RenderingPipeline *)p));
            }
        }
    }
}