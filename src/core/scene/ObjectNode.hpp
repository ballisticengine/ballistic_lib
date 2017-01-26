#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "Node.hpp"
#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"

namespace Ballistic {
    namespace Core {
        namespace Scene {
            using Ballistic::Core::Types::Graphics::Mesh;
            using Ballistic::Core::Types::Graphics::Materials::Material;

            struct ObjectData {
                Mesh *mesh;
                Material *material;
                void *additionalData;
            };
            
//            class ObjectNode : public Node {
//            protected:
//                Mesh *mesh;
//                Material *material;
//            public:
//                ObjectNode(Mesh *mesh, Material *material);
//                Mesh * getMesh();
//                Material *getMaterial();
//                
//
//
//            };
        }
    }
}

#endif

