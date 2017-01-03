#ifndef UVMAP_HPP
#define UVMAP_HPP

#include "../spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                
                typedef Ballistic::Core::Types::Spatial::Vector3d UV;
                
                struct UVTriangle {
                    size_t indices[3];
                };
                
                struct UVMap {
                    UVTriangle *triangles;
                    UV *uvs;
                    size_t count;
                };
            }
        }
    }
}

#endif 

