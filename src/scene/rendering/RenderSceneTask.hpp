#ifndef RENDERMESHES_HPP
#define RENDERMESHES_HPP


#include "../../rendering/renderingPipeline/RenderingTask.hpp"
#include "../Node.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"

namespace Ballistic {
    namespace Scene {

        class RenderSceneTask : public Ballistic::Rendering::Pipeline::RenderingTask {
        protected:
            Node *rootNode;
            virtual void renderNode(Ballistic::Rendering::Pipeline::RenderingPipeline *p, 
                Node *node);
            virtual void run(Ballistic::Rendering::Pipeline::RenderingPipeline *p);

        public:
            virtual void setRootNode(Node *node);

        };
    }

}


#endif 

