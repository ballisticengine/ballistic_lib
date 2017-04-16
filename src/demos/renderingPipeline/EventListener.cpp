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
            x=10;
            break;
         
    }

    cout << "x: " << x << "|y:" << y << "|z:" << z << endl;
    //this->rootNode->translate(0, 0, z);
    this->rootNode->updateChildren();
    cout << this->rootNode->getTranslation().z << endl;
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
