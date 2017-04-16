#include "Node.hpp"


namespace Ballistic {

    namespace Scene {

        Node::Node() {
            this->matrixCalculator.identity(this->getMatrix());
            this->matrixCalculator.identity(&this->localMatrix);
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

        void Node::updateChildren() {
            this->dirty=false;
            std::vector<Node *> children = this->getChildren();
            using Ballistic::Core::Types::Spatial::Matrix4;
            for (auto c : children) {
               
                    Matrix4 *m = c->getMatrix();
                    Matrix4 tmpm;
                    tmpm = *m;

                    
                    /* error:
                     * it's multipled by parent matrix everytime, even its already multipled
                     * so its accumulating
                     * solution:
                     * add local and origin matrices to nodes and multiply it to matrix here
                     * and then each node would update itself where
                     * matrix = origin * local
                     */
                    
                    this->matrixCalculator.multiply(&tmpm, m, &this->matrix);
                    
                    *m = tmpm;
                    
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
            this->dirty=true;

        }

        void Node::translate(Ballistic::Core::Types::scalar_t x, Ballistic::Core::Types::scalar_t y, Ballistic::Core::Types::scalar_t z) {
            this->translate(Ballistic::Core::Types::Spatial::Vector3d(x, y, z));
        }

        Ballistic::Core::Types::Spatial::Vector3d & Node::getTranslation() {
            return this->translation;
        }
    }
}