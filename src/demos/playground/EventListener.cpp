#include "EventListener.hpp"
#include "../../core/types/common.hpp"
#include <iostream>

using namespace std;

using namespace Ballistic::Core::Types;

void EventListener::processKey(IoEvent *ioe) {

    scalar_t x, y, z;

    x = y = z = 0;

    switch (ioe->keyData.keycode) {
        case 'w':
            z = -1;
            break;
        case 's':
            z = 1;
            break;

        case 'a':
            x = -1;
            break;

        case 'd':
            x = 1;
            break;

    }

    this->rootNode->translate(x, y, z);
    this->rootNode->update();    
}

void EventListener::processEvent(void *e) {
    IoEvent *ioe = (IoEvent *) e;

    switch (ioe->type) {
        case IoEventType::IOEVENT_EXIT:
            this->system->shutdown();
            break;
        case IoEventType::IOEVENT_KEYUP:

            this->processKey(ioe);
            // cout << "UP " << ioe->keyData.keycode << endl;

            break;
    }
}

EventListener::EventListener(Node *rootNode) : rootNode(rootNode) {
    ModuleManager *m = ModuleManager::get();
    this->system = (System *) m->getModule("system");

}
