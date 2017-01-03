#include "AbstractMeshBuilder.hpp"


namespace Ballistic {
    namespace Core {
        namespace Builders {

            AbstractMeshBuilder::AbstractMeshBuilder() {
                this->vertexPerPoly = 0;
            }

            void AbstractMeshBuilder::startPolygon() {
                this->currentPoly = MeshPolygon();
            }

            void AbstractMeshBuilder::addPolyVertex(Vector3d coords) {
                this->vertexCounter++;

                this->currentPoly.vertices.push_back(coords);
            }

            void AbstractMeshBuilder::addPolyNormal(Vector3d coords) {
                this->currentPoly.normals.push_back(coords);
            }

            void AbstractMeshBuilder::addPolyUV(Vector3d coords) {
                this->currentPoly.uvs.push_back(coords);
            }

            void AbstractMeshBuilder::endPolygon() {
                if (this->vertexPerPoly == 0) {
                    this->vertexPerPoly = this->vertexCounter;
                }
                this->vertexCounter = 0;

                this->polygons.push_back(currentPoly);
            }

            void AbstractMeshBuilder::addPolyVertex(size_t index) {
                this->addPolyVertex(this->indexableVertices[index]);
            }

            void AbstractMeshBuilder::addPolyNormal(size_t index) {
                this->addPolyNormal(this->indexableNormals[index]);
            }

            void AbstractMeshBuilder::addPolyUV(size_t index) {
                this->addPolyUV(this->indexableUVs[index]);
            }

            void AbstractMeshBuilder::addIndexableVertex(Vector3d coords) {
                this->indexableVertices.push_back(coords);
            }

            void AbstractMeshBuilder::addIndexableNormal(Vector3d coords) {
                this->indexableNormals.push_back(coords);
            }
            
            void AbstractMeshBuilder::addIndexableUV(Vector3d coords) {
                this->indexableUVs.push_back(coords);
            }
        }
    }
}