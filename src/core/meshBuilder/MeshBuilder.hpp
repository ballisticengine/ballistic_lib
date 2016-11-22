#ifndef MESHBUILDER_HPP
#define	MESHBUILDER_HPP
#include "types/spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            using Ballistic::Core::Types::Spatial::Vector3d;
            class MeshBuilder {
            
            
            protected:
            public:
                void addVertex(Vector3d &coords);
            };
        }
    }
}


#endif	

