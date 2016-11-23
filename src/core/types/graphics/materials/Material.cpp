#include "Material.hpp"


namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {

                    Material::Material() {
                        this->shaderId = "none";
                    }

                    void * Material::getMaterialData() {
                        return (void *) this;
                    }

                    std::string Material::getShaderId() {
                        return this->shaderId;
                    }

                    void Material::setShaderId(std::string shaderId) {
                        this->shaderId = shaderId;
                    }
                }
            }
        }
    }
}
