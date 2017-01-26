#include "FrameTask.hpp"
#include "../../rendering/VBO/VboManager.hpp"
#include "modules/ModuleManager.hpp"
#include "../../core/calc/MatrixCalculator.hpp"
#include "../../core/types/spatial/Vector3d.hpp"


using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Calc;
using namespace Ballistic::Core::Types::Spatial;

FrameTask::FrameTask() {
    MatrixCalculator mc;

    mc.identity(&m);

    mc.translate(&m, Vector3d(0, 0, -10));
}

void FrameTask::run(RenderingPipeline *p) {
//    using Ballistic::Rendering::Vbo::VboManager;
//    ModuleManager *mgr = ModuleManager::get();
//    VboManager *vboMgr = (VboManager *) mgr->getModule("vboManager");
//
//
//
//
//
//
//    p->getRenderer()->renderVbo(vboMgr->getVbo("test"), m);


}