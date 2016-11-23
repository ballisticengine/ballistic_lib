#ifndef SIMPLECOLORMATERIAL_HPP
#define SIMPLECOLORMATERIAL_HPP

#include "Material.hpp"
#include "../Color.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {
                    using Ballistic::Core::Types::Graphics::Color;

                    class SimpleColorMaterial : public Material {
                    protected:
                        Color color;
                    public:
                        SimpleColorMaterial(Color  color);
                        Color & getColor();
                        std::string getType();
                    };
                }
            }
        }
    }
}

#endif

