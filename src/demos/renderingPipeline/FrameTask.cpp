#include "FrameTask.hpp"
#include "../../rendering/VBO/VboManager.hpp"
#include "modules/ModuleManager.hpp"
using namespace Ballistic::Core::Modules;




void FrameTask::run(RenderingPipeline *p) {
  using Ballistic::Rendering::Vbo::VboManager;
    ModuleManager *mgr = ModuleManager::get();
    VboManager *vboMgr = (VboManager *) mgr->getModule("vboManager");
    
    p->getRenderer()->renderVbo(vboMgr->getVbo("test"));
    
}