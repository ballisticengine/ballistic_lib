#include "VboManager.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {

            void VboManager::initialize() {

            }

            void VboManager::destroy() {

            }

            void VboManager::addVbo(std::string id, void * vboId) {
                this->vboMap[id] = vboId;
            }

            void* VboManager::getVbo(std::string id) {
                return this->vboMap[id];
            }
        }
    }
}

