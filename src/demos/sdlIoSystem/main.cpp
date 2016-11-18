#include "pipeline/Pipeline.hpp"
#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "Base/System.hpp"
#include "SDL/SDLIoDriver.hpp"

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;
using namespace Ballistic::IO::System;
using namespace Ballistic::IO::SDL;

int main() {

    ModuleManager *m = ModuleManager::get();
    //     m->addModule("sdlIo", &sdlio);
    //    m->initialize("sdlIo");
    //    p = m->getModule<SdlIo>("sdlIo");
    //    p->mainLoop();

    SDLIoDriver *io = new SDLIoDriver();
    System *system = new System();
    
    m->addModule("system", (Module *) system, (void *)io);
    m->initialize("system");
    system->eventLoop();
    return 0;
}