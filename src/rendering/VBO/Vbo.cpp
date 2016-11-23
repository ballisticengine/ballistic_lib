#include "Vbo.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {
            Vbo::Vbo(const Ballistic::Core::Types::Graphics::Mesh *mesh, void *rendererData)
            : mesh(mesh), rendererData(rendererData) {
                
            }
        }
    }
}
