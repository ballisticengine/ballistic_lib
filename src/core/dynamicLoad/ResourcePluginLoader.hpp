#ifndef RESOURCE_PLUGINLOADER_HPP
#define RESOURCE_PLUGINLOADER_HPP

#include <string>

#include "PluginLoader.hpp"



namespace Ballistic {
    namespace Core {
        namespace DynamicLoad {
            class ResourcePluginLoader : public PluginLoader {
            public:
                ResourcePluginLoader(std::string wd);
                 void * getLoader(std::string ext, std::string type = "none");
            };
        }
    }
}

#endif
