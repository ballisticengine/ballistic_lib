#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Event.hpp"

namespace Ballistic {
    namespace Core {
        namespace Events {
            class Listener {
            public:
                virtual void processEvent(void *e);
                Listener() {};
                
            };
        }
    }
}
#endif 

