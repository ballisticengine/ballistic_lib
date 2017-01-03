#ifndef LOADER_DEPENDENCY_HPP
#define LOADER_DEPENDENCY_HPP
#include <string>

#include "../ResourceHandle.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {

            struct Dependency {
                std::string resourceId, type;
                void **target;
                
            };

            typedef std::vector<Dependency> dependencyVector;

        }
    }
}
#endif 

