#include "MeshNode.hpp"

using Ballistic::Core::Types::Graphics::Mesh;
using Ballistic::Core::Types::Graphics::Materials::Material;
using Ballistic::Rendering::Renderable;

namespace Ballistic {

    namespace Scene {

        MeshNode::MeshNode(Mesh *mesh, Material *material, Renderable *renderable)
        : Node(), mesh(mesh), material(material), renderable(renderable) {

        }

        Mesh * MeshNode::getMesh() {
            return mesh;
        }

        Material *MeshNode::getMaterial() {
            return material;
        }
        
        Renderable * MeshNode::getRenderable() {
            return renderable;
        }
        
        
        void MeshNode::draw(Ballistic::Rendering::Renderers::RendererInterface *renderer) {
            renderer->setTransformMatrix(&this->matrix);
            renderer->render(renderable);
        }
    }

}
