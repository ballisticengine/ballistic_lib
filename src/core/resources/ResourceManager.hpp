#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "../modules/Module.hpp"
#include "storage/ResourceStorageHandler.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {
            using Ballistic::Core::Resources::Storage::ResourceStorageHandler;
            class ResourceManager : public Ballistic::Core::Modules::Module {
            protected:
                ResourceStorageHandler *storageHandler;
            public:
                ResourceManager(ResourceStorageHandler *storageHandler);
            };
        }
    }
}

#endif