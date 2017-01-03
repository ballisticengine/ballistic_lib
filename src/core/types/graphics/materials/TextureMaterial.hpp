#ifndef TEXTUREMATERIAL_HPP
#define TEXTUREMATERIAL_HPP

#include "Material.hpp"
#include "../Texture.hpp"
#include "../../spatial/Vector3d.hpp"
#include "../UVMap.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {


                    class TextureMaterial : public Material {
                    protected:
                        Ballistic::Core::Types::Graphics::Texture *texture;
                        Ballistic::Core::Types::Graphics::UVMap *uvMap;

                    public:
                        TextureMaterial(Ballistic::Core::Types::Graphics::Texture *texture,
                                  Ballistic::Core::Types::Graphics::UVMap *uvMap);
                        
                        virtual std::string getType();
                        virtual UVMap *getUVMap();
                        virtual Texture *getTexture();
                    };
                }
            }
        }
    }
}



#endif /* TEXTUREMATERIAL_HPP */

