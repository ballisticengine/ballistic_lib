#ifndef VBO_HPP
#define VBO_HPP

#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {
            class Vbo {
            public:
                Vbo(const Ballistic::Core::Types::Graphics::Mesh *mesh, 
                        const Ballistic::Core::Types::Graphics::Materials::Material *material,
                        void *rendererData);
                
                const Ballistic::Core::Types::Graphics::Mesh *mesh;
                const Ballistic::Core::Types::Graphics::Materials::Material *material;
                void *rendererData;
            };
        }
    }
}

#endif 

