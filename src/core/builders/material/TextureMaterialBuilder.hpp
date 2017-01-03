#include "AbstractMaterialBuilder.hpp"

#ifndef TEXTUREMATERIALBUILDER_HPP
#define TEXTUREMATERIALBUILDER_HPP

#include <vector>
#include "MaterialPolygon.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {
            class TextureMaterialBuilder : public AbstractMaterialBuilder {
            protected:
                
                
            public: 
                virtual Ballistic::Core::Types::Graphics::Materials::Material * build();
            };
        }
    }
}

#endif 

