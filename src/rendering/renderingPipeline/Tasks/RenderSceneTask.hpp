#ifndef RENDERMESHES_HPP
#define RENDERMESHES_HPP


#include "../RenderingTask.hpp"
#include "../../renderers/RendererInterface.hpp"
#include "../../../core/scene/Node.hpp"
#include "../RenderingPipeline.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {
            class RenderSceneTask : public RenderingTask {
                
            protected:
                Ballistic::Core::Scene::Node *rootNode;
                virtual void renderNode(RenderingPipeline *p, Ballistic::Core::Scene::Node *node);
                virtual void run(RenderingPipeline *p);
                
            public:
                virtual void setRootNode(Ballistic::Core::Scene::Node *node);
                
            };
        }
    }
}


#endif 

