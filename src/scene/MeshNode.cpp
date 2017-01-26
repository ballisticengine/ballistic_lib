#include "MeshNode.hpp"

using Ballistic::Core::Types::Graphics::Mesh;
using Ballistic::Core::Types::Graphics::Materials::Material;
using Ballistic::Rendering::Vbo::Vbo;

namespace Ballistic {

    namespace Scene {

        MeshNode::MeshNode(Mesh *mesh, Material *material, Vbo *vbo)
        : mesh(mesh), material(material), vbo(vbo) {

        }

        Mesh * MeshNode::getMesh() {
            return mesh;
        }

        Material *MeshNode::getMaterial() {
            return material;
        }
        
        Vbo * MeshNode::getVbo() {
            return vbo;
        }
        
        
        void MeshNode::draw(Ballistic::Rendering::Renderers::RendererInterface *renderer) {
            renderer->concatMatrix(&this->matrix);
            renderer->renderVbo(this->vbo);
        }
    }

}
