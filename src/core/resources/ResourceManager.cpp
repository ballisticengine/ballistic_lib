#include "ResourceManager.hpp"
#include "../resources/loader/Results.hpp"


namespace Ballistic {
    namespace Core {
        namespace Resources {

            ResourceManager::ResourceManager(ResourceStorageHandler *storageHandler)
            : storageHandler(storageHandler) {

            }

            Ballistic::Core::PluginLoad::ResourcePluginLoader & ResourceManager::getLoader() {
                return this->pluginLoader;
            }

            ResourceHandle & ResourceManager::get(std::string resourceId, Ballistic::Core::Resources::ResourceType type) {

                if (resourceMap.find(resourceId) == resourceMap.end()) {
                    Loader *loader = (Loader *)this->pluginLoader.
                            getLoaderByType(type);

                    using Ballistic::Core::Resources::Storage::FileData;
                    using Ballistic::Core::Resources::MeshAndMaterialResult;

                    FileData fileData = this->storageHandler->getResource(resourceId);

                    void *loadedData = loader->loadFromData(fileData.data, fileData.size);


                    ResourceHandle *handle = new
                            ResourceHandle(resourceId, type, loadedData);


                    this->resourceMap[resourceId] = handle;
                    this->resolveDependencies(loader);

                    return *handle;
                } else {
                    return *this->resourceMap[resourceId];
                }

            }

            void ResourceManager::resolveDependencies(Loader *loader) {
                dependencyVector dependencies = loader->getDependencies();
                for (size_t i = 0; i < dependencies.size(); i++) {

                    ResourceHandle handle = this->get(dependencies[i].resourceId, dependencies[i].type);
                    *dependencies[i].target = handle.getData();

                }
                loader->cleanDependencies();
            }
        }
    }
}
