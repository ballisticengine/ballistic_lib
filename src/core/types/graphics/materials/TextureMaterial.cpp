#include "TextureMaterial.hpp"


namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {

                    TextureMaterial::TextureMaterial(Ballistic::Core::Types::Graphics::Texture *texture,
                            Ballistic::Core::Types::Graphics::UVMap *uvMap)
                    : Material(), texture(texture), uvMap(uvMap) {

                    }

                    std::string TextureMaterial::getType() {
                        return "Texture";
                    }

                    UVMap *TextureMaterial::getUVMap() {
                        return this->uvMap;
                    }

                    Texture *TextureMaterial::getTexture() {
                        return this->texture;
                    }
                }
            }
        }
    }
}



