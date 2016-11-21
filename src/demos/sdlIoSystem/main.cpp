#include <iostream>
#include "pipeline/Pipeline.hpp"
#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "Base/System.hpp"
#include "SDL/SDLIoDriver.hpp"
#include "Base/IoEvent.hpp"

using namespace std;
using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;
using namespace Ballistic::IO::System;
using namespace Ballistic::IO::SDL;

class EventLogic : public Module {
protected:
    System *system;
public:
    EventLogic() : Module() {};
    virtual void initialize() {
        ModuleManager *m = ModuleManager::get();
       this->system = (System *)m->getModule("system");
    }
    
    virtual void destroy() {
        
    }
    
    virtual void processEvent(void *e) {
        IoEvent *ioe = (IoEvent *)e;
        
       
        if(ioe->type==IoEventType::IOEVENT_EXIT) {
            
            this->system->shutdown();
        }
    }
    
    
};

int main() {

    ModuleManager *m = ModuleManager::get();


    SDLIoDriver *io = new SDLIoDriver();
    EventLogic *el = new EventLogic();
    
    System *system = new System(io, m->getDispatcher());
    
    
    m->addModule("system", system);
    m->addModule("eventLogic", el);
    m->getDispatcher()->addListener("ioEvent", el);
    
    m->initialize();
    system->eventLoop();
    m->destroy();
    
    return 0;
}