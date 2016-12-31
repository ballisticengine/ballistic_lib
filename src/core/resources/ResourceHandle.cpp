#include "ResourceHandle.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {

            ResourceHandle::ResourceHandle(std::string id, std::string type, void *data)
            : id(id), type(type), data(data)  {
                //this->refCount = 1;
            }

            std::string ResourceHandle::getId() {
                return this->id;
            }

            void ResourceHandle::link() {
                this->refCount++;
            }

            void ResourceHandle::unlink() {
                this->refCount--;
            }

            size_t ResourceHandle::getRefCount() {
                return this->refCount;
            }

            void * ResourceHandle::getData() {
                return this->data;
            }

          

            ResourceHandle::~ResourceHandle() {
                if (this->data) { //TODO: solve void problem. use pool https://isocpp.org/wiki/faq/dtors#memory-pools
                    delete this->data;
                }
            }
        }
    }
}