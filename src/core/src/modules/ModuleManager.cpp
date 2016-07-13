#include "ModuleManager.hpp"

namespace Ballistic {
    namespace Core {
        namespace Modules {

            void ModuleManager::initialize(const std::string name) {
                Module *m = this->getModule<Module>(name);
                m->initialize();
            }

            void ModuleManager::destroy(const std::string name) {
                Module *m = this->getModule<Module>(name);
                m->destroy();
                //TODO: remove from dict or add isDestroyed flag to modules
            }
            
            void ModuleManager::initialize() {
                for(auto i: this->modules) {
                    this->initialize(i.first);
                }
            }
            
            void ModuleManager::destroy() {
                for(auto i: this->modules) {
                    this->destroy(i.first);
                }
            }
        }
    }
}

