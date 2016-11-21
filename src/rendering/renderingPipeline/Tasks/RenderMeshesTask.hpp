#ifndef RENDERMESHES_HPP
#define RENDERMESHES_HPP


#include "../RenderingTask.hpp"
#include "../../renderers/RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {
            class RenderMeshesTask : public RenderingTask {
            protected:
                virtual void run(RenderingPipeline *p);
            };
        }
    }
}


#endif 

