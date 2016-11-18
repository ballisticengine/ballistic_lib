#ifndef TASKGROUP_HPP
#define TASKGROUP_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace Pipeline {

            class TaskGroup {
            protected:
                std::string name;
            public:
                TaskGroup(std::string name);
//                void runAll();
//                void runTask(const std::string taskName);
//                void addTask(const std::string name, const Task *task);
//                void removeTask(const std::string name);
            };
        }
    }
}


#endif 

