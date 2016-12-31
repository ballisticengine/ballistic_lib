#ifndef FILESYSTEMSTORAGEHANDLER_HPP
#define FILESYSTEMSTORAGEHANDLER_HPP

#include "../../helpers/WithWD.hpp"
#include "ResourceStorageHandler.hpp"



namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Storage {

                class FilesystemStorageHandler :
                public ResourceStorageHandler,
                public Ballistic::Helpers::WithWD {
                public:
                    virtual FileData getResource(std::string resourceId);


                };

            }
        }
    }
}

#endif 

