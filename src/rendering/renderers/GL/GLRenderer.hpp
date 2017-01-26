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
                
                virtual void renderVbo(Ballistic::Rendering::Vbo::Vbo* vbo);
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
                
                virtual void renderVbo(Ballistic::Rendering::Vbo::Vbo* vbo,
                        Ballistic::Core::Types::Spatial::Matrix4 &matrix);

                virtual void renderVbo(Ballistic::Rendering::Vbo::Vbo* vbo,
                        Ballistic::Core::Types::Spatial::Vector3d & translation,
                        Ballistic::Core::Types::Spatial::Vector3d &rotation);

                virtual void setupTexture(Ballistic::Core::Types::Graphics::Texture *texture);

            };
        }
    }
}

#endif 

