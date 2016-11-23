#ifndef TRIMESHBUILDER_HPP
#define TRIMESHBUILDER_HPP
#include "AbstractMeshBuilder.hpp"
#include "types/graphics/Mesh.hpp"
namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using namespace Ballistic::Core::Types::Graphics;

            class TriMeshBuilder : public AbstractMeshBuilder {
            protected:
                vector<Vector3d> vertices, normals;
                Triangle *triangles;
                
                virtual size_t addVertex(Vector3d v);
                size_t  addNormal(Vector3d v);
                size_t addIfNotExists(Vector3d v, vector<Vector3d> &vectors);
                virtual size_t findVector(Vector3d & v, vector<Vector3d> & vectors);

            public:
                TriMeshBuilder();
                virtual void * build();
            };
        }
    }
}

#endif 

