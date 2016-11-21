#ifndef PIPELINETASK_HPP
#define PIPELINETASK_HPP

namespace Ballistic {
    namespace Core {
        namespace Pipeline {
            class Pipeline;
            class Task {
            protected:
                virtual void run(Pipeline *p) = 0;
                friend class Pipeline;
            public:
                
            };
        }
    }
}

#endif 

