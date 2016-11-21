#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Event.hpp"

namespace Ballistic {
    namespace Core {
        namespace Events {
            class Listener {
            public:
                //TODO: callback map here and dispatcher with callback name method
                virtual void processEvent(void *e);
                Listener() {};
                
            };
        }
    }
}
#endif 

