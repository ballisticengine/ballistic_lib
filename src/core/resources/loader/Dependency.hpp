#ifndef LOADER_DEPENDENCY_HPP
#define LOADER_DEPENDENCY_HPP
#include <string>

namespace Ballistic {
    namespace Core {
        namespace Resources {

            struct Dependency {
                std::string file_name, type;
                void **target;
            };

        }
    }
}
#endif 

