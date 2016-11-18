#ifndef IODRIVER_HPP
#define IODRIVER_HPP

#include "IoEvent.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {
            class System;
            
            class IoDriver {
            protected:
                virtual void transform(void *rawEvent, Ballistic::IO::System::IoEvent *event)=0;
                virtual void *poolEvent()=0;
                virtual void initialize(void *params) = 0;
                virtual void destroy() = 0;   
                friend class System;
            public:
                
            };
        }
    }
}

#endif

