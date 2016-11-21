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

            void ModuleManager::addModule(std::string name, void *m, void *initData, long int ordering) {
                Module *mod = (Module *) m;
                if (initData) {
                    mod->setInitData(initData);
                }
                mod->initialized = false;
                this->modules.insert(std::pair<std::string, void *>(name, (void *) mod));
            }

            void *ModuleManager::getModule(const std::string name) {
                return this->modules[name];
            }

            void ModuleManager::initialize(const std::string name) {
                Module *m = (Module *)this->getModule(name);

                if (!m->initialized) {
                    m->initialized = true;
                    m->initialize();

                }
            }

            void ModuleManager::destroy(const std::string name) {
                Module *m = (Module *)this->getModule(name);
                if (m->initialized) {
                    m->initialized = false;
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
            
            Ballistic::Core::Events::Dispatcher * ModuleManager::getDispatcher() {
                return &this->dispatcher;
            }
        }
    }
}

