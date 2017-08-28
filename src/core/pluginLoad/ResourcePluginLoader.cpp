#include "ResourcePluginLoader.hpp"

namespace Ballistic {
    namespace Core {
        namespace PluginLoad {

            ResourcePluginLoader::ResourcePluginLoader() {

            }
            
//            void * LibLoad::getLoaderByExtension(string ext, ResourceType type) {
//    for (size_t i = 0; i < loads.size(); i++) {
//        Loader * loader = (Loader *) loads[i].module_class;
//
//        if (loader->handlesEntension(ext) && (loader->getType() == type || type == NONE)) {
//
//            return loads[i].module_class;
//        }
//    }
//    return 0;
//}


            Ballistic::Core::Resources::Loader * ResourcePluginLoader::getLoaderByType( Ballistic::Core::Resources::ResourceType type) {
                /*
                 TODO: Add map for types by priority to speed up this process
                 */
                for (auto i: this->plugins) {
                    Ballistic::Core::Resources::Loader  * loader = (Ballistic::Core::Resources::Loader *) 
                           i.second.module_class;

                    if ( (loader->getType() == type)) {

                       return loader;
                    }
                }
                return 0;
            }
        }
    }
}