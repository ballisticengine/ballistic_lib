#include "TriMeshBuilder.hpp"
#include <iterator>
#include <algorithm>

namespace Ballistic {
    namespace Core {
        namespace Builders {
            using namespace std;

           

            size_t TriMeshBuilder::addVertex(Vector3d v) {
                return addIfNotExists(v, vertices);
            }

            size_t TriMeshBuilder::addNormal(Vector3d v) {
                return addIfNotExists(v, normals);
            }
            
            size_t  TriMeshBuilder::addUV(Vector3d v) {
                return addIfNotExists(v, uvs); 
            }

            

            Ballistic::Core::Types::Graphics::Mesh * TriMeshBuilder::build() {
                Mesh *m = new Mesh();
                m->n_triangles = polygons.size();

                m->triangles = new Triangle[m->n_triangles];

                size_t poly_i = 0;
                size_t vertex_i;
                for (auto i : this->polygons) {
                    vertex_i = 0;
                    for (auto v : i.vertices) {
                        size_t index = this->addVertex(v);
                        m->triangles[poly_i].indices[vertex_i] = index;
                        vertex_i++;
                    }

                    vertex_i = 0;
                    for (auto n : i.normals) {
                        size_t index = this->addNormal(n);
                        m->triangles[poly_i].normals[vertex_i] = index;
                    }
                    
                    

                    poly_i++;
                }

                m->n_vertices = vertices.size();
                m->vertices = new Vector3d[m->n_vertices];

                for (size_t i = 0; i < m->n_vertices; i++) {
                    m->vertices[i] = vertices[i];
                }

                m->n_normals = normals.size();
                m->normals = new Vector3d[m->n_normals];


                for (size_t i = 0; i < m->n_normals; i++) {
                    m->normals[i] = normals[i];
                }
                
                

                return m;
            }
        }
    }
}