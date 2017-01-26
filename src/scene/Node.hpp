#ifndef NODE_HPP
#define NODE_HPP

#include "../core/types/spatial/Vector3d.hpp"
#include "../core/types/spatial/Matrix.hpp"
#include "../rendering/renderers/RendererInterface.hpp"
#include <vector>

namespace Ballistic {
        namespace Scene {

            //TODO: Transform node should lead to actual typed node, 
            // typed node (like mesh) should transform
            // so typed node = leaf
            // node should be more general
            // leaf, transform, etc should be child classes
            /*
             OR pass renderer interface to node and make virtual draw function
             */
            
            enum class NodeType {
                TYPE_TRANSFORM,
                TYPE_SCENE,
                TYPE_MESH,
                TYPE_SPRITE,
            };
            
            class Node { 
            protected:
                /*
                 * TODO:
                     include rotation and translation vectors synced with matrix
                 */
                Ballistic::Core::Types::Spatial::Matrix4 matrix;
                std::vector<Node *> children;
                Node *parent;
                NodeType type;
                void *data;
                
            public:
      
                virtual void setType(NodeType type);
                //virtual void setParent(Node *parent);
                virtual void addChild(Node *child);
                virtual Ballistic::Core::Types::Spatial::Matrix4 * getMatrix();
                virtual NodeType getType();
                virtual  std::vector<Node *> & getChildren();
                virtual Node * getParent();
                virtual void draw(Ballistic::Rendering::Renderers::RendererInterface *renderer)=0;
                
            };

        }
}

#endif 

