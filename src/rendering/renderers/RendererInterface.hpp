#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"
#include "types/graphics/Texture.hpp"
#include "../VBO/Vbo.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            using Ballistic::Core::Types::Graphics::Mesh;
            using Ballistic::Rendering::Vbo::Vbo;
            using Ballistic::Core::Types::Graphics::Materials::Material;
            class RendererInterface {
            public:
                virtual void initialize()=0;
                virtual void destroy()=0;
                virtual void resize(int w, int h)=0;
                virtual void start()=0;
                virtual void end()=0;
                virtual Vbo* makeVbo(const Mesh &m,  Material &mtl)=0;
                virtual void renderVbo(Vbo* vbo)=0;
                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture)=0;
                
            };
        }
    }
}

#endif 

