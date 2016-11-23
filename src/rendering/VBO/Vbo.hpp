#ifndef VBO_HPP
#define VBO_HPP

#include "types/graphics/Mesh.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {
            class Vbo {
            public:
                Vbo(const Ballistic::Core::Types::Graphics::Mesh *mesh, void *rendererData);
                const Ballistic::Core::Types::Graphics::Mesh *mesh;
                void *rendererData;
            };
        }
    }
}

#endif 

