#ifndef PLUGINLOADER_HPP
#define PLUGINLOADER_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <dlfcn.h>
#include <boost/filesystem.hpp>

#include "Plugin.hpp"

namespace Ballistic {
    namespace Core {
        namespace DynamicLoad {

            namespace fs = boost::filesystem;

            typedef std::vector<Plugin> lib_vector;
            typedef std::map<std::string, Plugin> lib_map;

            class PluginLoader {
            protected:
                lib_map libs;
                lib_vector loads;
                void error(std::string name);
                Plugin loadLib(std::string file_name, std::string entry_point_name);
                std::string wd;
            public:
                PluginLoader(std::string wd);
                void registerPlugin(std::string file_name);
                void discoverPlugins();

                void registerPlugin(std::string name, std::string file_name, std::string entry_point_name);
                void * getPluginClass(std::string name);
                lib_vector & getAllLoaders();
                ~PluginLoader();
//                virtual void setWD(std::string wd);
//                virtual std::string getWD();

            };
        }
    }
}



#endif /* LIBLOAD_HPP */

