#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"
#include "types/graphics/Texture.hpp"
#include "../../core/types/spatial/Matrix.hpp"
#include "../../core/types/spatial/Vector3d.hpp"
#include "../renderable/Renderable.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            class RendererInterface {
            public:
                virtual void initialize() = 0;
                virtual void destroy() = 0;
                virtual void resize(int w, int h) = 0;
                virtual void start() = 0;
                virtual void end() = 0;
                virtual Ballistic::Rendering::Renderable*
                makeRenderable(Ballistic::Core::Types::Graphics::Mesh &m,
                        Ballistic::Core::Types::Graphics::Materials::Material &mtl) = 0;
                
                virtual void setTransformMatrix(Ballistic::Core::Types::Spatial::Matrix4 *matrix)=0;
    
                virtual void render( Ballistic::Rendering::Renderable* renderable) = 0;
                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture) = 0;

            };
        }
    }
}

#endif 

