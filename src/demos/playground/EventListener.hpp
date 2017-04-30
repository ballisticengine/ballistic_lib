#ifndef EVENTMODULE_HPP
#define EVENTMODULE_HPP


#include "modules/ModuleManager.hpp"

#include "Base/System.hpp"
#include "events/Listener.hpp"
#include "../../scene/Node.hpp"

using namespace Ballistic::Core::Events;
using namespace Ballistic::IO::System;
using namespace Ballistic::Scene;

class EventListener : public Listener {
protected:
    System *system;
    Node *rootNode;
    void processKey(IoEvent *ioe);
public:
    EventListener(Node *rootNode);

    virtual void processEvent(void *e);


};

#endif 

