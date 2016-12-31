#include "ResourceManager.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {

            ResourceManager::ResourceManager(ResourceStorageHandler *storageHandler)
            : storageHandler(storageHandler) {

            }

            Ballistic::Core::PluginLoad::ResourcePluginLoader & ResourceManager::getLoader() {
                return this->pluginLoader;
            }

            ResourceHandle & ResourceManager::get(std::string resourceId, std::string type) {
                
                if (resourceMap.find(resourceId) == resourceMap.end()) {
                    Loader *loader = (Loader *)this->pluginLoader.
                            getLoaderByType(type);
                    
                    using Ballistic::Core::Resources::Storage::FileData;
                    
                    FileData fileData = this->storageHandler->getResource(resourceId);
                    
                    ResourceHandle *handle = new 
                            ResourceHandle(resourceId, type, loader->loadFromData(fileData.data, fileData.size));
                    
                    
                    this->resourceMap[resourceId] = handle;
                    return *handle;
                } else {
                    return *this->resourceMap[resourceId];
                }
                
            }
        }
    }
}
