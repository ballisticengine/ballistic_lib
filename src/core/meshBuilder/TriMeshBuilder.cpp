#include "TriMeshBuilder.hpp"
#include <iterator>
#include <algorithm>

namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using namespace std;

            TriMeshBuilder::TriMeshBuilder() : AbstractMeshBuilder() {

            }

            
            size_t TriMeshBuilder::addIfNotExists(Vector3d v, vector<Vector3d> &vectors) {
                size_t index = findVector(v, vectors);
                if (index == -1) {
                    vectors.push_back(v);
                    return vectors.size()-1;
                }

                return index;
            }
            
            
            size_t TriMeshBuilder::addVertex(Vector3d v) {
                return addIfNotExists(v, vertices);
            }

            size_t TriMeshBuilder::addNormal(Vector3d v) {
                return addIfNotExists(v, normals);
            }

            size_t TriMeshBuilder::findVector(Vector3d & v, vector<Vector3d> & vectors) {
                auto it = std::find(vectors.begin(), vectors.end(), v);
                if (it == vectors.end()) {
                    return -1;
                } else {
                    return distance(vectors.begin(), it);
                }

                
            }

            void * TriMeshBuilder::build() {
                Mesh *m = new Mesh();
                m->n_triangles = polygons.size();
                
                m->triangles = new Triangle[m->n_triangles];
                
                size_t poly_i = 0;
                size_t vertex_i;
                for (auto i : this->polygons) {
                    vertex_i = 0;
                    for (auto v : i.vertices) {
                        size_t index = this->addVertex(v);
                        m->triangles[poly_i].indices[vertex_i]=index;
                        vertex_i++;
                    }
                    
                    vertex_i = 0;
                    for(auto n: i.normals) {
                        size_t index = this->addNormal(n);
                        m->triangles[poly_i].normals[vertex_i]=index;
                    }
                    
                    poly_i++;
                }
                
                m->n_vertices = vertices.size();
                m->vertices = new Vector3d[m->n_vertices];
                
                for(size_t i=0; i<m->n_vertices; i++) {
                    m->vertices[i] = vertices[i];
                }

                return m;
            }
        }
    }
}