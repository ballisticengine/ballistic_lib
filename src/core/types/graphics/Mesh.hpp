#ifndef MODEL_HPP
#define MODEL_HPP

#include "../spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Types {
        namespace Graphics {

            struct UV {
                scalar_t u, v;
            };

            struct Triangle {
                Ballistic::Types::Spatial::Vector3d normals[3];
                UV uvs[3];
                size_t indices[3];
            };

            struct Mesh {
                Ballistic::Types::Spatial::Vector3d *vertices;
                Triangle *triangles;
                size_t n_vertices, n_triangles;
            };
        }
    }
}



#endif 

