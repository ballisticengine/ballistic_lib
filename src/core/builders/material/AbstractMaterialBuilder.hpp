#ifndef ABSTRACTMATERIALBUILDER_HPP
#define ABSTRACTMATERIALBUILDER_HPP

#include <vector>

#include "../AbstractBuilder.hpp"
#include "../material/AbstractMaterialBuilder.hpp"
#include "MaterialPolygon.hpp"
#include "types/spatial/Vector3d.hpp"
#include "../../types/graphics/materials/Material.hpp"
#include "../../types/graphics/Texture.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {

            class AbstractMaterialBuilder : public AbstractBuilder {
            protected:
                std::vector<Ballistic::Core::Types::Spatial::Vector3d> uvs, indexableUVs;
                std::vector<Ballistic::Core::Types::Graphics::Texture *> textures, indexableTextures;
                std::vector<MaterialPolygon> polygons;
                MaterialPolygon currentPoly;
                
            public:
                AbstractMaterialBuilder();
                virtual void startPolygon();
                virtual void addPolyUV(Ballistic::Core::Types::Spatial::Vector3d coords);
                virtual void addPolyUV(size_t index);
                virtual void setPolyTexture(Ballistic::Core::Types::Graphics::Texture *texture);
                virtual void setPolyTexture(size_t index);
                virtual void endPolygon();
                virtual void addIndexableUV(Ballistic::Core::Types::Spatial::Vector3d coords);
                virtual void addIndexableTexture(Ballistic::Core::Types::Graphics::Texture *texture);
                virtual Ballistic::Core::Types::Graphics::Materials::Material * build() = 0;
            };
        }
    }
}

#endif 

