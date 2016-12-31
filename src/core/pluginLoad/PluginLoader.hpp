#ifndef PLUGINLOADER_HPP
#define PLUGINLOADER_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <dlfcn.h>
#include <boost/filesystem.hpp>

#include "PluginHandle.hpp"
#include "../helpers/WithWD.hpp"

namespace Ballistic {
    namespace Core {
        namespace PluginLoad {

            namespace fs = boost::filesystem;

           
            typedef std::map<std::string, PluginHandle> PluginMap;

            class PluginLoader : public Ballistic::Helpers::WithWD {
            protected:
                PluginMap plugins;
                void error(std::string name);
                PluginHandle loadLib(std::string file_name, std::string entry_point_name);
                
            public:
                PluginLoader();
//                void registerPlugin(std::string file_name);
                void discoverPlugins();

                void registerDynamicPlugin(std::string name, std::string file_name, std::string entry_point_name);
                void registerStaticPlugin(std::string name, void *pluginClass);
                void * getPluginClass(std::string name);
                PluginMap & getAllLoaders();
                ~PluginLoader();


            };
        }
    }
}



#endif /* LIBLOAD_HPP */

