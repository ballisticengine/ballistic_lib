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
                std::map<const std::string, void *> modules;
                static ModuleManager *instance;
                ModuleManager();
            public:
                static ModuleManager *get();

                virtual void addModule(std::string name, void *m, void *initData = 0, long int ordering = -1) {
                    Module *mod = (Module *) m;
                    if (initData) {
                        mod->setInitData(initData);
                    }
                    mod->isInitialized = false;
                    mod->isDestroyed = false;
                    this->modules.insert(std::pair<std::string, void *>(name, (void *) mod));

                }

                virtual void *getModule(const std::string name) {
                    return this->modules[name];
                }

                virtual void initialize(const std::string name);
                virtual void destroy(const std::string name);
                virtual void initialize();
                virtual void destroy();
            };

        }
    }
}

#endif 

