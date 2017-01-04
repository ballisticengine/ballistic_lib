#include "EventListener.hpp"

#include <iostream>

using namespace std;

void EventListener::processEvent(void *e) {
    IoEvent *ioe = (IoEvent *) e;

    switch (ioe->type) {
        case IoEventType::IOEVENT_EXIT:
            this->system->shutdown();
            break;
        case IoEventType::IOEVENT_KEYUP:
            cout << "UP" << endl;
            break;
    }
}

EventListener::EventListener() {
    ModuleManager *m = ModuleManager::get();
    this->system = (System *) m->getModule("system");
}
