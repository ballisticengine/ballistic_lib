#ifndef UVPOLYGON_HPP
#define UVPOLYGON_HPP

#include <vector>
#include "../../types/spatial/Vector3d.hpp"
#include "../../types/graphics/Texture.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {
            struct MaterialPolygon {
                std::vector<Ballistic::Core::Types::Spatial::Vector3d> uvs;
                Ballistic::Core::Types::Graphics::Texture *texture;
            };
        }
    }
}

#endif 

