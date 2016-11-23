#include "modules/ModuleManager.hpp"
#include "types/graphics/Mesh.hpp"
#include "types/spatial/Vector3d.hpp"
#include "SDL/SDLIoDriver.hpp"
#include "meshBuilder/TriMeshBuilder.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"
#include "../../rendering/renderers/GL/GLRenderer.hpp"
#include "../../rendering/renderingPipeline/Tasks/BeginFrameTask.hpp"
#include "../../rendering/renderingPipeline/Tasks/EndFrameTask.hpp"

#include "EventListener.hpp"
#include "TickListener.hpp"
#include "../../rendering/VBO/VboManager.hpp"
#include "FrameTask.hpp"


using namespace Ballistic::Core::Modules;
using namespace Ballistic::IO::SDL;
using Ballistic::Core::Types::Graphics::Mesh;
using Ballistic::Core::Types::Graphics::Triangle;
using Ballistic::Core::Types::Spatial::Vector3d;
using Ballistic::Rendering::Vbo::VboManager;
using Ballistic::Core::MeshBuilder::TriMeshBuilder;

int main() {
    ModuleManager *mgr = ModuleManager::get();
    SDLIoDriver *io = new SDLIoDriver();

    System *system = new System(io, mgr->getDispatcher());
    Ballistic::Rendering::Renderers::GLRenderer rdr;
    Ballistic::Rendering::Pipeline::RenderingPipeline rpl(&rdr);
    VboManager vboMgr;

    Ballistic::Rendering::Pipeline::BeginFrameTask bft;
    Ballistic::Rendering::Pipeline::EndFrameTask eft;
    FrameTask ft;

    rpl.addTask("begin", &bft);
    rpl.addTask("frame", &ft);
    rpl.addTask("end", &eft);


    mgr->addModule("system", system);
    mgr->addModule("rendering", &rpl);
    mgr->addModule("vboManager", &vboMgr);

    EventListener *el = new EventListener();
    TickListener *tl = new TickListener();


    mgr->getDispatcher()->addListener("ioEvent", el);
    mgr->getDispatcher()->addListener("ioTick", tl);

    TriMeshBuilder mb;

    mb.startPolygon();
    mb.addPolyVertex(Vector3d(0, -1, 0));
    mb.addPolyVertex(Vector3d(0, 1, 0));
    mb.addPolyVertex(Vector3d(1, 1, 0));
    mb.endPolygon();

    Mesh *m = (Mesh *) mb.build();

    mgr->initialize("system");
    mgr->initialize("rendering");

    vboMgr.addVbo("test", rdr.makeMeshVbo(*m));
    system->eventLoop();
    mgr->destroy();

    delete m;
    delete el;
    delete tl;
    delete system;

}
