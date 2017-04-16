#ifndef NODE_HPP
#define NODE_HPP

#include "../core/types/spatial/Vector3d.hpp"
#include "../core/types/spatial/Matrix.hpp"
#include "../core/calc//MatrixCalculator.hpp"
#include "../rendering/renderers/RendererInterface.hpp"
#include <vector>

namespace Ballistic {
        namespace Scene {
            
            
            //TODO: verify need for defining type here
            // ie. give option to return typeid int
            enum class NodeType {
                TYPE_TRANSFORM,
                TYPE_SCENE,
                TYPE_MESH,
                TYPE_SPRITE,
            };
            
            class Node { 
            protected:
                //TODO: dirty flag
                // //http://gameprogrammingpatterns.com/dirty-flag.html
                Ballistic::Core::Types::Spatial::Matrix4 matrix, localMatrix, originMatrix;
                Ballistic::Core::Types::Spatial::Vector3d rotation;
                Ballistic::Core::Types::Spatial::Vector3d translation;
                std::vector<Node *> children; //maybe a list? and supposedly pointers in vector are bad
                Node *parent;
                NodeType type;
                void *data;
                //TODO: static calculator. got from matrix - static there too
                Ballistic::Core::Calc::MatrixCalculator matrixCalculator; 
                bool dirty;
            public:
                Node();
      
                virtual void setType(NodeType type);
                virtual void addChild(Node *child);
                
                
                virtual void translate(Ballistic::Core::Types::scalar_t x,Ballistic::Core::Types::scalar_t y, Ballistic::Core::Types::scalar_t z);
                virtual void translate(Ballistic::Core::Types::Spatial::Vector3d  translation);
                virtual Ballistic::Core::Types::Spatial::Vector3d & getTranslation();
                
                virtual void update();
                
                virtual Ballistic::Core::Types::Spatial::Matrix4  *getMatrix();
                //virtual void setOriginMatrix(Ballistic::Core::Types::Spatial::Matrix4 origin);
                
                //TODO set origin matrix and/or translate origin
                
                virtual NodeType getType();
                virtual  std::vector<Node *> & getChildren();
                virtual bool hasChildren();
                virtual Node * getParent();
                virtual void draw(Ballistic::Rendering::Renderers::RendererInterface *renderer)=0;
                
            };

        }
}

#endif 

