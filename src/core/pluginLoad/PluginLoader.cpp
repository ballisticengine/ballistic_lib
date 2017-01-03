#include "PluginLoader.hpp"

namespace Ballistic {
    namespace Core {
        namespace PluginLoad {
               namespace fs = boost::filesystem;
            PluginLoader::PluginLoader() {
                
            }

            void PluginLoader::error(std::string name) {
                std::cout << "Library " << name << " error: " << dlerror() << std::endl;
            }

            //            void PluginLoader::registerPlugin(std::string file_name) {
            //
            //                plugins[file_name]=loadLib(file_name, "returnLoader");
            //            }

            void PluginLoader::discoverPlugins() { //TODO: better discovery, maybe move to other subclass
                std::cout << "Discovering loaders..." << std::endl;
                fs::path l_path(this->wd + "/loaders");
                fs::directory_iterator end_itr;
                for (fs::directory_iterator itr(l_path); itr != end_itr; ++itr) {
                    std::cout << "Registering " << itr->path().string() << std::endl;
                    //this->registerPlugin(itr->path().string());
                }
            }

            PluginMap & PluginLoader::getAllLoaders() {
                return this->plugins;
            }

            PluginHandle PluginLoader::loadLib(std::string file_name, std::string entry_point_name) {
                PluginHandle module;
                module.entry_point_name = entry_point_name;
                module.file_name = file_name;

                std::string full_file_name = file_name;
                module.handle = dlopen(full_file_name.c_str(), RTLD_NOW | RTLD_GLOBAL);

                if (!module.handle) {
                    error(module.file_name + " file ");
                }
                typedef void* (*module_f)();

                module_f fn = (module_f) dlsym(module.handle, entry_point_name.c_str());

                if (!fn) {
                    error(entry_point_name + " function ");
                }

                module.module_class = (void *) fn();
                return module;
            }

            void PluginLoader::registerDynamicPlugin(std::string name,
                    std::string file_name,
                    std::string entry_point_name) {

                PluginHandle module = this->loadLib(this->wd + "/" + file_name + ".so", entry_point_name);
                plugins[name] = module;
            }

            void PluginLoader::registerStaticPlugin(std::string name, void *pluginClass) {
                PluginHandle module;
                module.handle = 0;
                module.module_class = pluginClass;
                plugins[name] = module;
            }

            void * PluginLoader::getPluginClass(std::string name) {
                return plugins[name].module_class;
            }

            PluginLoader::~PluginLoader() {
                for (auto i = plugins.begin(); i != plugins.end(); i++) {
                    if (i->second.handle) {
                        dlclose(i->second.handle);
                    }
                }
            }
        }
    }
}