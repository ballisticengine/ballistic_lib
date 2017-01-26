#ifndef TRANSFORMNODE_HPP
#define TRANSFORMNODE_HPP

#include "Node.hpp"

namespace Ballistic {
        namespace Scene {
            
            class TransformNode : public Node {
            public:
                virtual void draw(Ballistic::Rendering::Renderers::RendererInterface *renderer);
            };
        }
}

#endif 

