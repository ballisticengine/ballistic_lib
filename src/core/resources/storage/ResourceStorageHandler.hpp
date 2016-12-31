#ifndef RESOURCESTORAGEINTERFACE_HPP
#define RESOURCESTORAGEINTERFACE_HPP

#include <string>
#include "FileData.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Storage {

                class ResourceStorageHandler {
                public:
                    virtual FileData getResource(std::string resourceId)=0;
                    //virtual void addResource(std::string resourceId, ResourceHandle resource)=0;
                };
            }
        }
    }
}


#endif
