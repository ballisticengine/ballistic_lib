#include "Object.hpp"


namespace Ballistic {
    namespace Scene {

        Object::Object(Mesh *mesh, Material *material) : mesh(mesh), material(material) {

        }

        Mesh * Object::getMesh() {
            return mesh;
        }

        Material *Object::getMaterial() {
            return material;
        }
    }
}
