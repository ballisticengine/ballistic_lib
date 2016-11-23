#ifndef MODEL_HPP
#define MODEL_HPP

#include "../spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {

                struct UV {
                    scalar_t u, v;
                };

                struct Triangle {
                    size_t normals[3];
                    size_t indices[3];
                };

                struct Mesh {
                    Ballistic::Core::Types::Spatial::Vector3d *normals;
                    Ballistic::Core::Types::Spatial::Vector3d *vertices;
                    Triangle *triangles;
                    size_t n_vertices, n_triangles;
                };
            }
        }
    }
}



#endif 

