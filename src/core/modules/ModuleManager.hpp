#ifndef MODULEMANAGER_HPP
#define MODULEMANAGER_HPP

#include <string>
#include <map>

#include "Module.hpp"
#include "../events/Dispatcher.hpp"

namespace Ballistic {
    namespace Core {
        namespace Modules {

            class ModuleManager {
            protected:
                std::map<const std::string, void *> modules;
                static ModuleManager *instance;
                ModuleManager();
                Ballistic::Core::Events::Dispatcher dispatcher;
            public:
                static ModuleManager *get();
                virtual void addModule(std::string name, void *m, void *initData = 0, long int ordering = -1);
                virtual void *getModule(const std::string name);
                virtual void initialize(const std::string name);
                virtual void destroy(const std::string name);
                virtual Ballistic::Core::Events::Dispatcher * getDispatcher();
                virtual void initialize(); //there is still error here
                /*
                 TODO: destroy should also unallocate memory for the module
                 * there should be a separate uninit function
                 * OR maybe not, sice module is created by user and it might be a 
                 * compile time allocated
                 */
                
                virtual void destroy();
            };

        }
    }
}

#endif 

