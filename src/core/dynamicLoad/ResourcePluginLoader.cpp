#include "ResourcePluginLoader.hpp"

namespace Ballistic {
    namespace Core {
        namespace DynamicLoad {

            ResourcePluginLoader::ResourcePluginLoader(std::string wd) : PluginLoader(wd) {

            }

            void * ResourcePluginLoader::getLoader(std::string ext, std::string type) {
//                for (size_t i = 0; i < loads.size(); i++) {
//                    Loader * loader = (Loader *) loads[i].module_class;
//
//                    if (loader->handlesEntension(ext) && (loader->getType() == type || type == NONE)) {
//
//                        return loads[i].module_class;
//                    }
//                }
                return 0;
            }
        }
    }
}