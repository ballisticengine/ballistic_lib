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

            class Pipeline : public Ballistic::Core::Modules::Module {
            protected:
                std::map<const std::string, const Task *> tasks;
                virtual void initialize();
                virtual void destroy();
            public:
                void runAll();
                void runTask(const std::string taskName);
                void addTask(const std::string name, const Task *task);
                void removeTask(const std::string name);
                virtual std::string getName();
            };

        }
    }
};

#endif 

