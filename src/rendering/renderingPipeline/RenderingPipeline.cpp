#include "RenderingPipeline.hpp"
#include "Tasks/BeginFrameTask.hpp"
#include "Tasks/EndFrameTask.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            RenderingPipeline::RenderingPipeline(Ballistic::Rendering::Renderers::RendererInterface* renderer) {
                this->renderer = renderer;
            }

            void RenderingPipeline::initialize() {
                this->renderer->initialize();
            }

            void RenderingPipeline::destroy() {
                this->renderer->destroy();
            }

            RendererInterface* RenderingPipeline::getRenderer() {
                return this->renderer;
            }
            
            void RenderingPipeline::addDefaultTasks() {
                this->addTask("begin", new BeginFrameTask());
                this->addTask("end", new EndFrameTask());
            }


        }
    }
}