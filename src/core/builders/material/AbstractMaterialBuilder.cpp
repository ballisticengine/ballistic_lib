#include "AbstractMaterialBuilder.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {

            AbstractMaterialBuilder::AbstractMaterialBuilder() {

            }

            void AbstractMaterialBuilder::startPolygon() {
                this->currentPoly = MaterialPolygon();
            }

            void AbstractMaterialBuilder::endPolygon() {
                this->polygons.push_back(currentPoly);
            }

            void AbstractMaterialBuilder::addPolyUV(Ballistic::Core::Types::Spatial::Vector3d coords) {
                this->currentPoly.uvs.push_back(coords);
            }

            void AbstractMaterialBuilder::addPolyUV(size_t index) {
                this->addPolyUV(this->indexableUVs[index]);
            }

            void AbstractMaterialBuilder::setPolyTexture(Ballistic::Core::Types::Graphics::Texture *texture) {
                this->currentPoly.texture = texture;
            }

            void AbstractMaterialBuilder::setPolyTexture(size_t index) {
                this->setPolyTexture(this->indexableTextures[index]);
            }

            void AbstractMaterialBuilder::addIndexableUV(Ballistic::Core::Types::Spatial::Vector3d coords) {
                this->indexableUVs.push_back(coords);
            }

            void AbstractMaterialBuilder::addIndexableTexture(Ballistic::Core::Types::Graphics::Texture * texture) {
                this->indexableTextures.push_back(texture);
            }

        }
    }
}