#include "EventListener.hpp"

void EventListener::processEvent(void *e) {
    IoEvent *ioe = (IoEvent *) e;

    switch (ioe->type) {
        case IoEventType::IOEVENT_EXIT:
            this->system->shutdown();
            break;
    }
}

EventListener::EventListener() {
    ModuleManager *m = ModuleManager::get();
    this->system = (System *) m->getModule("system");
}
