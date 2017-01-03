#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include <map>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../RendererInterface.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {
            class GLRenderer : public RendererInterface {
            protected:
                void setUpShaders();
                std::map<Ballistic::Core::Types::Graphics::Texture *, GLuint> textureMap;
            public:
                virtual void initialize();
                virtual void destroy();
                virtual void resize(int w, int h);
                virtual void start();
                virtual void end();
                virtual Vbo * makeVbo(const Mesh &m,  Material &mtl);
                virtual void renderVbo(Vbo * vbo);
                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture);
          
            };
        }
    }
}

#endif 

