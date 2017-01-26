#include "RenderSceneTask.hpp"
#include "../../../core/scene/ObjectNode.hpp"

#include <iostream>
using namespace Ballistic::Core::Scene;
using namespace std;


namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            void RenderSceneTask::renderNode(RenderingPipeline *p, Ballistic::Core::Scene::Node *node) {

                if (node->getType() == Ballistic::Core::Scene::NodeType::TYPE_MESH) {
                    ObjectData *data = (ObjectData *) node->getData();
                    p->getRenderer()->renderVbo((Ballistic::Rendering::Vbo::Vbo*)data->additionalData, *node->getMatrix());
                } else {
                    p->getRenderer()->setTransformMatrix(node->getMatrix());
                }

                vector<Node *>children = node->getChildren();

                for (auto i : children) {
                    renderNode(p, i);
                    p->getRenderer()->setTransformMatrix(node->getMatrix());
                }
            }

            void RenderSceneTask::run(RenderingPipeline *p) {

                this->renderNode(p, this->rootNode);
            }

            void RenderSceneTask::setRootNode(Ballistic::Core::Scene::Node *node) {
                this->rootNode = node;
            }
        }
    }
}
