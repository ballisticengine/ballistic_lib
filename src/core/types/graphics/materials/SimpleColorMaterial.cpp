#include "SimpleColorMaterial.hpp"


namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {

                    SimpleColorMaterial::SimpleColorMaterial(Color  color) : Material() {
                        this->color = color;
                    }

                    std::string  SimpleColorMaterial::getType() {
                        return "SimpleColor";
                    }
                }
            }
        }
    }
}

