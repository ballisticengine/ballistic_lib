#include "Node.hpp"


namespace Ballistic {

    namespace Scene {

        Node::Node() {
            this->matrixCalculator.identity(this->getMatrix());
            this->matrixCalculator.identity(&this->localMatrix);
            this->matrixCalculator.identity(&this->originMatrix);
            this->dirty = true;
        }

        void Node::setType(NodeType type) {
            this->type = type;
        }

        void Node::addChild(Node *child) {
            child->parent = this;
            child->originMatrix = this->matrix;
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

        void Node::update() {
            using Ballistic::Core::Types::Spatial::Matrix4;
            this->matrixCalculator.multiply(&this->matrix, &this->originMatrix, &this->localMatrix);
            std::vector<Node *> children = this->getChildren();
            for (auto c : children) {
                c->originMatrix = this->matrix;
                c->update();
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
            this->matrixCalculator.translate(&this->localMatrix, translation);
            this->dirty = true;

        }

        void Node::translate(Ballistic::Core::Types::scalar_t x, Ballistic::Core::Types::scalar_t y, Ballistic::Core::Types::scalar_t z) {
            this->translate(Ballistic::Core::Types::Spatial::Vector3d(x, y, z));
        }

        Ballistic::Core::Types::Spatial::Vector3d & Node::getTranslation() {
            return this->translation;
        }
    }
}