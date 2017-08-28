#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>

#include "ResourceHandle.hpp"
#include "storage/ResourceStorageHandler.hpp"
#include "../modules/Module.hpp"
#include "../pluginLoad/ResourcePluginLoader.hpp"
#include "loader/Loader.hpp"
#include "loader/ResourceType.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {
            using Ballistic::Core::Resources::Storage::ResourceStorageHandler;
            class ResourceManager : public Ballistic::Core::Modules::Module {
            protected:
                ResourceStorageHandler *storageHandler;
                Ballistic::Core::PluginLoad::ResourcePluginLoader pluginLoader;
                std::map<std::string, ResourceHandle *> resourceMap;
            public:
                virtual void initialize() {} 
                virtual void destroy() {}
                ResourceManager(ResourceStorageHandler *storageHandler);
                virtual void resolveDependencies(Loader *loader);
                ResourceHandle & get(std::string resourceId,  Ballistic::Core::Resources::ResourceType type);
                 Ballistic::Core::PluginLoad::ResourcePluginLoader & getLoader();
//                size_t unlink(std::string resourceId);
//                size_t unlink(ResourceHandle & res);
            };
        }
    }
}

#endif