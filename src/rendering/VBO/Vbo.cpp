#include "Vbo.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {
            Vbo::Vbo(const Ballistic::Core::Types::Graphics::Mesh *mesh, 
                    const Ballistic::Core::Types::Graphics::Materials::Material *material,
                    void *rendererData)
            : mesh(mesh), material(material), rendererData(rendererData) {
                
            }
        }
    }
}
