
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
        }
    }
}