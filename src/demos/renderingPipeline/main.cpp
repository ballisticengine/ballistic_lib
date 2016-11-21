#include "modules/ModuleManager.hpp"
#include "SDL/SDLIoDriver.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"
#include "../../rendering/renderers/GL/GLRenderer.hpp"

#include "EventListener.hpp"
#include "TickListener.hpp"


using namespace Ballistic::Core::Modules;
using namespace Ballistic::IO::SDL;

int main() {
    ModuleManager *mgr = ModuleManager::get();
    SDLIoDriver *io = new SDLIoDriver();

    System *system = new System(io, mgr->getDispatcher());
     Ballistic::Rendering::Renderers::GLRenderer rdr;
    Ballistic::Rendering::Pipeline::RenderingPipeline rpl(&rdr);
    
    rpl.addDefaultTasks();
    
    
    mgr->addModule("system", system);
    mgr->addModule("rendering", &rpl);

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
