#include "Node.hpp"

namespace Ballistic {
    namespace Core {
        namespace Scene {

          

            void Node::setType(NodeType type) {
                this->type = type;
            }

            void Node::setParent(Node *parent) {
                this->parent = parent;
                
            }

            void Node::addChild(Node *child) {
                child->setParent(this);
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

             void Node::setData(void *data) {
                this->data = data;
            }
            
            void * Node::getData() {
                return this->data;
            }
            
            Ballistic::Core::Types::Spatial::Matrix4 * Node::getMatrix() {
                return &this->matrix;
            }
        }
    }
}