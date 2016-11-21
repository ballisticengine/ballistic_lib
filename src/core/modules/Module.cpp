
#include "Module.hpp"

namespace Ballistic {
    namespace Core {
        namespace Modules {

            void Module::setInitData(void *initData) {
                this->initData = initData;
            }

            void* Module::getInitData() {
                return this->initData;
            }
            
            bool Module::isInitialized() {
                return this->initialized;
            }

            Module::Module() {
                
            }
        }
    }
}