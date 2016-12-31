#ifndef RESOURCE_PLUGINLOADER_HPP
#define RESOURCE_PLUGINLOADER_HPP

#include <string>

#include "PluginLoader.hpp"
#include "../resources/loader/Loader.hpp"


namespace Ballistic {
    namespace Core {
        namespace PluginLoad {
            class ResourcePluginLoader : public PluginLoader {
            public:
                ResourcePluginLoader();
                 Ballistic::Core::Resources::Loader * getLoaderByType(std::string type);
                 
            };
        }
    }
}

#endif
