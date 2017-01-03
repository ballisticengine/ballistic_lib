#include "TextureMaterialBuilder.hpp"

#include "../../types/graphics/UVMap.hpp"
#include "../../types/graphics/materials/TextureMaterial.hpp"


namespace Ballistic {
    namespace Core {
        namespace Builders {

            Ballistic::Core::Types::Graphics::Materials::Material * TextureMaterialBuilder::build() {
                
                using namespace Ballistic::Core::Types::Graphics;
                using namespace Ballistic::Core::Types::Graphics::Materials;
                
                UVMap *uvMap = new UVMap();
                uvMap->count = this->polygons.size();
                uvMap->triangles = new UVTriangle[uvMap->count];
                uvMap->uvs = new UV[this->uvs.size()];

                
                size_t vertex_i, poly_i;

                for (auto i : this->polygons) {
                    vertex_i = 0;
                    
                    for (auto u : i.uvs) {
                        size_t index = this->addIfNotExists(u, this->uvs);
                        uvMap->triangles[poly_i].indices[vertex_i] = index;
                        vertex_i++;
                    }
                    
                    poly_i++;
                }
                
                TextureMaterial *material = new TextureMaterial(this->currentPoly.texture, uvMap);
                
                return material;
            }
        }
    }
}