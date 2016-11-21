#include "modules/ModuleManager.hpp"
#include "SDL/SDLIoDriver.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"

#include "EventListener.hpp"
#include "TickListener.hpp"


using namespace Ballistic::Core::Modules;
using namespace Ballistic::IO::SDL;

int main() {
    ModuleManager *mgr = ModuleManager::get();
    SDLIoDriver *io = new SDLIoDriver();

    System *system = new System(io, mgr->getDispatcher());

    mgr->addModule("system", system);


    EventListener *el = new EventListener();
    TickListener *tl = new TickListener();

    mgr->getDispatcher()->addListener("ioEvent", el);
    mgr->getDispatcher()->addListener("ioTick", tl);

    mgr->initialize();
    system->eventLoop();
    mgr->destroy();

    delete el;
    delete tl;
    delete system;

}
