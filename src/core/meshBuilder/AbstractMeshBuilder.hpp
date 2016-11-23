#ifndef MESHBUILDER_HPP
#define	MESHBUILDER_HPP

#include <vector>

#include "types/spatial/Vector3d.hpp"
#include "Polygon.hpp"

namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using Ballistic::Core::Types::Spatial::Vector3d;
            using std::vector;
            
            class AbstractMeshBuilder {
            protected:
                size_t vertexPerPoly, vertexCounter, polyCounter;
                vector<Polygon> polygons;
                Polygon currentPoly;
            public:
                AbstractMeshBuilder();
                virtual void startPolygon();
                virtual void addVertex(Vector3d &coords);
                virtual void addNormal(Vector3d &coords);
                virtual void endPolygon();
                
                virtual void * build()=0;
            };
        }
    }
}


#endif	

