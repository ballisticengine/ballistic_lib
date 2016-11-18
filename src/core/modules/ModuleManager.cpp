#include "ModuleManager.hpp"
#include <iostream>
using namespace std;
namespace Ballistic {
    namespace Core {
        namespace Modules {

            ModuleManager *ModuleManager::instance = 0;

            ModuleManager::ModuleManager() {
            }

            ModuleManager* ModuleManager::get() {
                if (!ModuleManager::instance) {
                    ModuleManager::instance = new ModuleManager();
                }

                return ModuleManager::instance;
            }

            void ModuleManager::initialize(const std::string name) {
                Module *m = (Module *)this->getModule(name);
                
                if (!m->isInitialized) {
                    m->isInitialized = true;
                    m->initialize();
                    
                }
            }

            void ModuleManager::destroy(const std::string name) {
                Module *m = (Module *)this->getModule(name);
                if(!m->isDestroyed) {
                    m->isDestroyed = true;
                    m->destroy();
                    
                }
               
            }

            void ModuleManager::initialize() {
                for (auto i : this->modules) {
                    this->initialize(i.first);
                }
            }

            void ModuleManager::destroy() {
                for (auto i : this->modules) {
                    this->destroy(i.first);
                }
            }
        }
    }
}

