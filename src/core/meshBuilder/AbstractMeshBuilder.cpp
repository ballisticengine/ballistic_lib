#include "AbstractMeshBuilder.hpp"


namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {

            AbstractMeshBuilder::AbstractMeshBuilder() {
                this->vertexPerPoly = 0;
            }

            void AbstractMeshBuilder::startPolygon() {
                this->currentPoly = Polygon();
            }

            void AbstractMeshBuilder::addPolyVertex(Vector3d coords) {
                this->vertexCounter++;

                this->currentPoly.vertices.push_back(coords);
            }

            void AbstractMeshBuilder::addPolyNormal(Vector3d coords) {
                this->currentPoly.normals.push_back(coords);
            }

            void AbstractMeshBuilder::endPolygon() {
                if (this->vertexPerPoly == 0) {
                    this->vertexPerPoly = this->vertexCounter;
                }
                this->vertexCounter = 0;
                
                this->polygons.push_back(currentPoly);
            }
        }
    }
}