#include "pipeline/Pipeline.hpp"
#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;

int main() {

    ModuleManager *m = new ModuleManager();
    SdlIo sdlio, *p;
    m->addModule("sdlIo", &sdlio);
    m->initialize("sdlIo");
    p = m->getModule<SdlIo>("sdlIo");
    p->mainLoop();
    return 0;
}