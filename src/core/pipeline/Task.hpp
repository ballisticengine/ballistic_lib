#ifndef PIPELINETASK_HPP
#define PIPELINETASK_HPP

namespace Ballistic {
    namespace Core {
        namespace Pipeline {

            class Task {
            public:
                virtual void run() = 0;
            };
        }
    }
}

#endif 

