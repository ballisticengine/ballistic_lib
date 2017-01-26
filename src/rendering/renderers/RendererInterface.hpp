#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"
#include "types/graphics/Texture.hpp"
#include "../../core/types/spatial/Matrix.hpp"
#include "../../core/types/spatial/Vector3d.hpp"
#include "../VBO/Vbo.hpp"

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
                virtual Ballistic::Rendering::Vbo::Vbo*
                makeVbo(const Ballistic::Core::Types::Graphics::Mesh &m,
                        Ballistic::Core::Types::Graphics::Materials::Material &mtl) = 0;
                
                virtual void setTransformMatrix(Ballistic::Core::Types::Spatial::Matrix4 *matrix)=0;
                virtual void concatMatrix(Ballistic::Core::Types::Spatial::Matrix4 *matrix)=0;
                //TODO: maybe also multmatrix
                //TODO: rename Vbo to Renderable
                
                
                virtual void renderVbo(Ballistic::Rendering::Vbo::Vbo* vbo) = 0; //pass matrix here



                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture) = 0;

            };
        }
    }
}

#endif 

