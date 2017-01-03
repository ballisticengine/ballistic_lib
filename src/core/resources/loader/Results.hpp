#ifndef RESULTS_HPP
#define RESULTS_HPP
#include "../../types/graphics/Mesh.hpp"
#include "../../types/graphics/materials/Material.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {
            struct MeshAndMaterialResult {
                Ballistic::Core::Types::Graphics::Mesh *mesh;
                Ballistic::Core::Types::Graphics::Materials::Material *material;
            };
        }
    }
}


#endif

