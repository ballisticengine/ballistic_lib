#include "RenderSceneTask.hpp"

#include <iostream>
using namespace Ballistic::Scene;
using namespace std;


namespace Ballistic {
    namespace Scene {
        RenderSceneTask::RenderSceneTask()
        {
            Ballistic::Core::Calc::MatrixCalculator mc;
            mc.identity(&this->identityMatrix);
        }
        
        
        void RenderSceneTask::renderNode(Ballistic::Rendering::Pipeline::RenderingPipeline *p, Node *node) {

            node->draw(p->getRenderer());
            
            vector<Node *>children = node->getChildren();
       
            for (auto i : children) {
                renderNode(p, i);
            }
        }

        void RenderSceneTask::run(Ballistic::Rendering::Pipeline::RenderingPipeline *p) {
            
            p->getRenderer()->setTransformMatrix(&this->identityMatrix);
            this->renderNode(p, this->rootNode);
        }

        void RenderSceneTask::setRootNode(Scene::Node *node) {
            this->rootNode = node;
        }
    }

}
