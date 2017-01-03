#ifndef TRIMESHBUILDER_HPP
#define TRIMESHBUILDER_HPP
#include "AbstractMeshBuilder.hpp"
#include "types/graphics/Mesh.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {
            using namespace Ballistic::Core::Types::Graphics;

            class TriMeshBuilder : public AbstractMeshBuilder {
            protected:
                vector<Vector3d> vertices, normals, uvs;
                Triangle *triangles;
                virtual size_t addVertex(Vector3d v);
                virtual size_t  addNormal(Vector3d v);
                virtual size_t  addUV(Vector3d v);
               

            public:
                virtual Ballistic::Core::Types::Graphics::Mesh * build();
            };
        }
    }
}

#endif 

