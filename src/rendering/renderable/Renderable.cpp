#include "Renderable.hpp"

namespace Ballistic {
    namespace Rendering {
        
            Renderable::Renderable(const Ballistic::Core::Types::Graphics::Mesh *mesh, 
                    const Ballistic::Core::Types::Graphics::Materials::Material *material,
                    void *rendererData)
            : mesh(mesh), material(material), rendererData(rendererData) {
                
            }
        }
    
}
