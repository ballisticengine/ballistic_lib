#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include <set>
#include <vector>
#include <map>

#include "Dependency.hpp"
#include "ResourceType.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {

           
            typedef std::set<std::string> extensionsSet;

            class Loader {
            protected:
                dependencyVector dependencies;
                virtual void addDependency(std::string resourceId, ResourceType type, void **target);
                std::map<std::string, std::string> params;
            public:
                Loader() {}
                virtual ~Loader() {}
                virtual extensionsSet getFileExtensions() = 0;
                virtual ResourceType getType() = 0;
                virtual size_t getPriority();                
                virtual void *loadFromData(char *data, size_t size) = 0;
                virtual bool handlesEntension(std::string extension);
                virtual dependencyVector getDependencies();
                virtual void cleanDependencies();

            };
        }
    }
}

#endif 

