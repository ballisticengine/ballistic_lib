#ifndef EVENTMODULE_HPP
#define EVENTMODULE_HPP


#include "modules/ModuleManager.hpp"

#include "Base/System.hpp"
#include "events/Listener.hpp"

using namespace Ballistic::Core::Events;
using namespace Ballistic::IO::System;


class EventListener : public Listener {
protected:
    System *system;
public:
    EventListener();
    
     virtual void processEvent(void *e);
    
    
};

#endif 

