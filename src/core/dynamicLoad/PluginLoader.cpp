#include "PluginLoader.hpp"

namespace Ballistic {
    namespace Core {
        namespace DynamicLoad {
            
            PluginLoader::PluginLoader(std::string wd) {
                this->wd = wd;
            }
            
            void PluginLoader::error(std::string name) {
                std::cout << "Library " << name << " error: " << dlerror() << std::endl;
            }

            void PluginLoader::registerPlugin(std::string file_name) {

                loads.push_back(loadLib(file_name, "returnLoader"));
            }



            void PluginLoader::discoverPlugins() {
                std::cout << "Discovering loaders..." << std::endl;
                fs::path l_path(this->wd + "/loaders");
                fs::directory_iterator end_itr;
                for (fs::directory_iterator itr(l_path); itr != end_itr; ++itr) {
                    std::cout << "Registering " << itr->path().string() << std::endl;
                    this->registerPlugin(itr->path().string());
                }
            }

            lib_vector & PluginLoader::getAllLoaders() {
                return this->loads;
            }

            Plugin PluginLoader::loadLib(std::string file_name, std::string entry_point_name) {
                Plugin module;
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

            void PluginLoader::registerPlugin(std::string name,
                    std::string file_name,
                    std::string entry_point_name) {

                Plugin module = this->loadLib(this->wd + "/" + file_name + ".so", entry_point_name);
                libs[name] = module;
            }

            void * PluginLoader::getPluginClass(std::string name) {
                return libs[name].module_class;
            }

            PluginLoader::~PluginLoader() {
                for (lib_map::iterator i = libs.begin(); i != libs.end(); i++) {
                    dlclose(i->second.handle);
                }
            }
        }
    }
}