#ifndef ABSTRACTBUILDER_HPP
#define ABSTRACTBUILDER_HPP

#include <vector>
#include "types/spatial/Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace Builders {

            class AbstractBuilder {
            protected:
                virtual size_t addIfNotExists(Ballistic::Core::Types::Spatial::Vector3d v,
                        std::vector<Ballistic::Core::Types::Spatial::Vector3d> &vectors);
                virtual size_t findVector(Ballistic::Core::Types::Spatial::Vector3d & v,
                        std::vector<Ballistic::Core::Types::Spatial::Vector3d> & vectors);
            };
        }
    }
}


#endif 

