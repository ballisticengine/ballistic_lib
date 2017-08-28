#include "Loader.hpp"
#include <cstdio>

namespace Ballistic {
    namespace Core {
        namespace Resources {

            bool Loader::handlesEntension(std::string extension) {
                extensionsSet exts = this->getFileExtensions();
                if (exts.find(extension) != exts.end()) {
                    return true;
                }
                return false;
            }

            void Loader::addDependency(std::string resourceId, ResourceType type, void **target) {
                Dependency dep;
                dep.resourceId = resourceId;
                dep.target = target;
                dep.type = type;
                dependencies.push_back(dep);
            }

            dependencyVector Loader::getDependencies() {
                return this->dependencies;
            }

            void Loader::cleanDependencies() {
                this->dependencies.clear();
            }

            

            size_t Loader::getPriority() {
                return 0;
            }

           
        }
    }
}