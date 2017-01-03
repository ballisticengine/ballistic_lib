#ifndef MESHBUILDER_HPP
#define	MESHBUILDER_HPP

#include <vector>

#include "types/spatial/Vector3d.hpp"
#include "../../types/graphics/Mesh.hpp"
#include "MeshPolygon.hpp"
#include "../Constants.hpp"
#include "../material/AbstractMaterialBuilder.hpp"
#include "../AbstractBuilder.hpp"


namespace Ballistic {
    namespace Core {
        namespace Builders {
            using Ballistic::Core::Types::Spatial::Vector3d;
            using std::vector;
            
            class AbstractMeshBuilder : public AbstractBuilder {
            protected:
                size_t vertexPerPoly, vertexCounter, polyCounter;
                vector<Vector3d> indexableVertices, indexableNormals, indexableUVs;
                vector<MeshPolygon> polygons;
                MeshPolygon currentPoly;
                
            public:
                AbstractMeshBuilder();
                //virtual void setDirection(FrontFaceDir sourceDirection, FrontFaceDir targetDirection);
                virtual void startPolygon();
                virtual void addPolyVertex(Vector3d coords);
                virtual void addPolyVertex(size_t index);
                virtual void addPolyNormal(Vector3d coords);
                virtual void addPolyNormal(size_t index);
                virtual void addPolyUV(Vector3d coords);
                virtual void addPolyUV(size_t index);
                virtual void endPolygon();
                virtual void addIndexableVertex(Vector3d coords);
                virtual void addIndexableNormal(Vector3d coords);
                virtual void addIndexableUV(Vector3d coords);
                //virtual void reset();
                
                virtual Ballistic::Core::Types::Graphics::Mesh * build()=0;
               
            };
        }
    }
}


#endif	

