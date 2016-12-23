#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>


#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "events/Dispatcher.hpp"
#include "events/Event.hpp"
#include "events/Listener.hpp"

using namespace std;
using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Events;

class EventTestModule : public Module {
protected:

    virtual void initialize() {
        this->once = this->buggy = this->eventful = false;
    }

    virtual void destroy() {

    }

public:
    bool eventful, buggy, once;

    void processEvent(void *e) {
        if (((Event *) e)->getName() == "testEvent") {
            this->eventful = true;
        } 
        else if(((Event *) e)->getName() == "testEvent3") {
            once=true;
        } else {
            this->buggy = true;
        }
    }
};

TEST(Dispatching, DispatcherTest) {
    ModuleManager *manager = ModuleManager::get();
    Dispatcher *d = manager->getDispatcher();
    EventTestModule *m = new EventTestModule();

    manager->addModule("eventTest", m);
    manager->initialize("eventTest");
    
    d->addListener("testEvent", (void *) m);
    
    Event *e1 = (Event *) d->dispatch(new Event("testEvent"));
    Event *e2 = (Event *) d->dispatch(new Event("testEvent2"));

    ASSERT_EQ(m->eventful, true);
    ASSERT_EQ(m->buggy, false);
    ASSERT_EQ(m->once, false);
    
    delete e1;
    delete e2;
    
    Event *e3 = (Event *)d->dispatchOnce(new Event("testEvent3"), m);
    ASSERT_EQ(m->once, true);
    
    delete e3;
}
