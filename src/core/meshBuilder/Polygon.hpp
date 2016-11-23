#ifndef POLY_HPP
#define POLY_HPP
#include <vector>
#include "types/spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using std::vector;
            using Ballistic::Core::Types::Spatial::Vector3d;

            struct Polygon {
                vector<Vector3d> vertices, normals;
            };
        }
    }
}


#endif 

