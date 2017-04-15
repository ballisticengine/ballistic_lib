#include "RenderSceneTask.hpp"

#include <iostream>
using namespace Ballistic::Scene;
using namespace std;


namespace Ballistic {
    namespace Scene {

        void RenderSceneTask::renderNode(Ballistic::Rendering::Pipeline::RenderingPipeline *p, Node *node) {

            node->draw(p->getRenderer());
            
            vector<Node *>children = node->getChildren();
       
            
            for (auto i : children) {
                renderNode(p, i);
                //p->getRenderer()->setTransformMatrix(node->getMatrix());
            }
        }

        void RenderSceneTask::run(Ballistic::Rendering::Pipeline::RenderingPipeline *p) {

            this->renderNode(p, this->rootNode);
        }

        void RenderSceneTask::setRootNode(Scene::Node *node) {
            this->rootNode = node;
        }
    }

}
