#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "Node.hpp"
#include "../core/types/graphics/Mesh.hpp"
#include "../core/types/graphics/materials/Material.hpp"
#include "../rendering/renderable/Renderable.hpp"

namespace Ballistic {

    namespace Scene {
        

        class MeshNode : public Node {
        protected:
            Ballistic::Core::Types::Graphics::Mesh *mesh;
            Ballistic::Core::Types::Graphics::Materials::Material *material;
            Ballistic::Rendering::Renderable *renderable;
        public:
            MeshNode(Ballistic::Core::Types::Graphics::Mesh *mesh, 
                    Ballistic::Core::Types::Graphics::Materials::Material *material, 
                    Ballistic::Rendering::Renderable *renderable);
            Ballistic::Core::Types::Graphics::Mesh * getMesh();
            Ballistic::Core::Types::Graphics::Materials::Material *getMaterial();
            Ballistic::Rendering::Renderable * getRenderable();
            virtual void draw(Ballistic::Rendering::Renderers::RendererInterface *renderer);

        };
    }

}

#endif

