#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "types/graphics/Mesh.hpp"
#include "../VBO/Vbo.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            using Ballistic::Core::Types::Graphics::Mesh;
            using Ballistic::Rendering::Vbo::Vbo;
            class RendererInterface {
            public:
                virtual void initialize()=0;
                virtual void destroy()=0;
                virtual void resize(int w, int h)=0;
                virtual void start()=0;
                virtual void end()=0;
                virtual Vbo* makeMeshVbo(const Mesh &m)=0;
                virtual void renderVbo(Vbo* vbo)=0;
                
            };
        }
    }
}

#endif 

