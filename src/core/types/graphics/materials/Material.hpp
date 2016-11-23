#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <string>

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                namespace Materials {

                    class Material {
                    protected:
                        std::string shaderId;
                    public:
                        Material();
                        virtual void * getMaterialData();
                        virtual std::string getType() = 0;
                        virtual std::string getShaderId();
                        virtual void setShaderId(std::string shaderId);
                    };
                }
            }
        }
    }
}

#endif 

