#ifndef EVENTLISTENER_HPP
#define EVENTLISTENER_HPP

#include <map>
#include <string>
#include <utility>


#include "Event.hpp"

namespace Ballistic {
    namespace Core {
        namespace Events {
            class Dispatcher {
            protected:
                std::multimap<std::string, void *> eventListeners;
                
            public:
                virtual void addListener(std::string eventName, void *target);
                virtual void * dispatch(void *e);
                //This one seems a bit pointless
                virtual void * dispatchOnce(void *e, void *target);
            };
        }
    }
}

#endif

