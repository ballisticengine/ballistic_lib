#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "Node.hpp"
#include "../core/types/graphics/Mesh.hpp"
#include "../core/types/graphics/materials/Material.hpp"
#include "../rendering/VBO/Vbo.hpp"

namespace Ballistic {

    namespace Scene {
        

        class MeshNode : public Node {
        protected:
            Ballistic::Core::Types::Graphics::Mesh *mesh;
            Ballistic::Core::Types::Graphics::Materials::Material *material;
            Ballistic::Rendering::Vbo::Vbo *vbo;
        public:
            MeshNode(Ballistic::Core::Types::Graphics::Mesh *mesh, 
                    Ballistic::Core::Types::Graphics::Materials::Material *material, 
                    Ballistic::Rendering::Vbo::Vbo *vbo);
            Ballistic::Core::Types::Graphics::Mesh * getMesh();
            Ballistic::Core::Types::Graphics::Materials::Material *getMaterial();
            Ballistic::Rendering::Vbo::Vbo * getVbo();
            virtual void draw(Ballistic::Rendering::Renderers::RendererInterface *renderer);

        };
    }

}

#endif

