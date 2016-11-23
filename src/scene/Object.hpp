#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "types/graphics/Mesh.hpp"
#include "types/graphics/materials/Material.hpp"

namespace Ballistic {
    namespace Scene {
        using Ballistic::Core::Types::Graphics::Mesh;
        using Ballistic::Core::Types::Graphics::Materials::Material;
        
        class Object {
        protected:
            Mesh *mesh;
            Material *material;
        public:
            Object(Mesh *mesh, Material *material);
            Mesh * getMesh();
            Material *getMaterial();
            
            
        };
    }
}

#endif

