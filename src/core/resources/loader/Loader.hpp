#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include <set>
#include <vector>
#include <map>

#include "Dependency.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {

            typedef std::vector<Dependency> dependencyVector;
            typedef std::set<std::string> extensionsSet;

            class Loader {
            protected:
                dependencyVector dependencies;
                virtual void addDependency(std::string file_name, void **target, std::string type);
                std::map<std::string, std::string> params;
            public:
                virtual extensionsSet getFileExtensions() = 0;
                virtual std::string getType() = 0;
                virtual size_t getPriority();
                virtual void *load(std::string file_name);
                virtual void *loadFromData(char *data, size_t size) = 0;
                virtual bool handlesEntension(std::string extension);
                virtual dependencyVector getDependencies();
                virtual void cleanDependencies();

            };
        }
    }
}

#endif 

