#include "Node.hpp"


namespace Ballistic {

    namespace Scene {

        Node::Node() {
            this->matrixCalculator.identity(this->getMatrix());
        }

        void Node::setType(NodeType type) {
            this->type = type;
        }

        void Node::addChild(Node *child) {
            child->parent = this;
            this->children.push_back(child);
        }

        NodeType Node::getType() {
            return this->type;
        }

        std::vector<Node *> & Node::getChildren() {
            return this->children;
        }

        bool Node::hasChildren() {
            return this->getChildren().size() > 0;
        }

        void Node::updateChildren() {
            std::vector<Node *> children = this->getChildren();
            using Ballistic::Core::Types::Spatial::Matrix4;
            for (auto c : children) {
                Matrix4 *m = c->getMatrix();
                this->matrixCalculator.multiply(m, &this->matrix, m);
                c->updateChildren();
            }

        }

        Node * Node::getParent() {
            return this->parent;
        }

        Ballistic::Core::Types::Spatial::Matrix4 * Node::getMatrix() {
            return &this->matrix;
        }

        void Node::translate(Ballistic::Core::Types::Spatial::Vector3d translation) {
            this->translation = this->translation + translation;
            this->matrixCalculator.translate(&this->matrix, translation);

        }

        Ballistic::Core::Types::Spatial::Vector3d & Node::getTranslation() {
            return this->translation;
        }
    }
}