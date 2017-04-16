#ifndef RENDERMESHES_HPP
#define RENDERMESHES_HPP


#include "../../rendering/renderingPipeline/RenderingTask.hpp"
#include "../Node.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"
#include "../../core/types/spatial/Matrix.hpp"
#include "../../core/calc/MatrixCalculator.hpp"

namespace Ballistic {
    namespace Scene {

        class RenderSceneTask : public Ballistic::Rendering::Pipeline::RenderingTask {
        protected:
            Node *rootNode;
            virtual void renderNode(Ballistic::Rendering::Pipeline::RenderingPipeline *p, 
                Node *node);
            virtual void run(Ballistic::Rendering::Pipeline::RenderingPipeline *p);
            Ballistic::Core::Types::Spatial::Matrix4 identityMatrix;
        public:
            virtual void setRootNode(Node *node);
            RenderSceneTask();

        };
    }

}


#endif 

