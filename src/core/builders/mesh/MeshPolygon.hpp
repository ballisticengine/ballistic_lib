#ifndef POLY_HPP
#define POLY_HPP
#include <vector>
#include "types/spatial/Vector3d.hpp"
#include "types/graphics/Texture.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {

            struct MeshPolygon {
                std::vector<Ballistic::Core::Types::Spatial::Vector3d> vertices, normals, uvs;
                
            };
        }
    }
}


#endif 

