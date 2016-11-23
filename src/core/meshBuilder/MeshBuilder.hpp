#ifndef MESHBUILDER_HPP
#define	MESHBUILDER_HPP
#include "types/spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using Ballistic::Core::Types::Spatial::Vector3d;
            class MeshBuilder {
            
            
            protected:
                size_t vertexPerPoly, vertexCounter;
            public:
                virtual void startPolygon();
                virtual void addVertex(Vector3d &coords);
                virtual void addNormal(Vector3d &normal);
                virtual void endPolygon();
            };
        }
    }
}


#endif	

