#include "Pipeline.hpp"

namespace Ballistic {
    namespace Core {
        namespace Pipeline {

            void Pipeline::addTask(const std::string name, const Task *task) {
                this->tasks.insert(std::pair<const std::string, const Task *>(name, task));
            }

            void Pipeline::runTask(const std::string taskName) {
                Task * t = (Task *)this->tasks[taskName];
                t->run(this);
            }

            void Pipeline::runAll() {
                this->run(this);
            }

            void Pipeline::removeTask(const std::string name) {
                ////   
            }

            
            void Pipeline::initialize() {

            }

            void Pipeline::destroy() {

            }
            
            void Pipeline::run(Pipeline *p) {
                for (auto i = this->tasks.begin(); i != this->tasks.end(); i++) {
                    this->runTask(i->first);
                }
            }
        }
    }
}