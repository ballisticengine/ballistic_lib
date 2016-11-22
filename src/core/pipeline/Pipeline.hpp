#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "modules/Module.hpp"
#include "Task.hpp"

#include <string>
#include <map>

namespace Ballistic {
    namespace Core {
        namespace Pipeline {

            /**
             TODO:
             * add task grouping
             */
       
            class Pipeline : public Ballistic::Core::Modules::Module, Task {
            protected:
                std::map<const std::string, const Task *> tasks;
                virtual void initialize();
                virtual void destroy();
                virtual void run(void *p);
            public:
                virtual void runAll();
                virtual void runTask(const std::string taskName);
                virtual void addTask(const std::string name, const Task *task);
                virtual void removeTask(const std::string name);
            };

        }
    }
};

#endif 

