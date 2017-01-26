#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include <map>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../RendererInterface.hpp"
#include "../../VBO/Vbo.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            class GLRenderer : public RendererInterface {
            protected:
                void setUpShaders();
                GLhandleARB setUpShader(std::string name, std::string vertText, std::string fragText);
                std::map<Ballistic::Core::Types::Graphics::Texture *, GLuint> textureMap;
                std::map<std::string, GLhandleARB> shaderMap;


            public:
                virtual void initialize();
                virtual void destroy();
                virtual void resize(int w, int h);
                virtual void start();
                virtual void end();
                virtual Ballistic::Rendering::Vbo::Vbo *
                makeVbo(const Ballistic::Core::Types::Graphics::Mesh &m,
                        Ballistic::Core::Types::Graphics::Materials::Material &mtl);

                virtual void setTransformMatrix(Ballistic::Core::Types::Spatial::Matrix4 *matrix);
                virtual void concatMatrix(Ballistic::Core::Types::Spatial::Matrix4 *matrix);

                virtual void renderVbo(Ballistic::Rendering::Vbo::Vbo* vbo);



                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture);

            };
        }
    }
}

#endif 

