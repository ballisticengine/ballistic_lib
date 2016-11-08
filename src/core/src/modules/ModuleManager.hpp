#ifndef MODULEMANAGER_HPP
#define MODULEMANAGER_HPP

#include <string>
#include <map>

#include "Module.hpp"

namespace Ballistic {
    namespace Core {
        namespace Modules {

            class ModuleManager {
            protected:
                std::map<const std::string, const void *> modules;
            public:

                template<typename T> void addModule(std::string name, T *m, void *initData = 0, long int ordering = -1) {
                    Module *module = (Module *) m;
                    if (initData) {
                        m->setInitData(initData);
                    }
                    this->modules.insert(std::pair<std::string, void *>(name, (void *) m));
                }

                template<typename T> T *getModule(const std::string name) {
                    return (T*)this->modules[name];
                }

                void initialize(const std::string name);
                void destroy(const std::string name);
                void initialize();
                void destroy();
            };

        }
    }
}

#endif 

