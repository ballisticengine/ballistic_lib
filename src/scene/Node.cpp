#include "Node.hpp"

namespace Ballistic {
    
        namespace Scene {

         
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

            Node * Node::getParent() {
                return this->parent;
            }

            
            Ballistic::Core::Types::Spatial::Matrix4 * Node::getMatrix() {
                return &this->matrix;
            }
        }
}