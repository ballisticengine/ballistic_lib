#include "VboManager.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {

            void VboManager::initialize() {

            }

            void VboManager::destroy() {

            }

            void VboManager::addVbo(std::string id, Vbo * vbo) {
                this->vboMap[id] = vbo;
            }

            Vbo* VboManager::getVbo(std::string id) {
                return this->vboMap[id];
            }
        }
    }
}

