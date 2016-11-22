#include "modules/ModuleManager.hpp"
#include "types/graphics/Mesh.hpp"
#include "types/spatial/Vector3d.hpp"
#include "SDL/SDLIoDriver.hpp"
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
    
    
//    rpl.addDefaultTasks();


    mgr->addModule("system", system);
    mgr->addModule("rendering", &rpl);
    mgr->addModule("vboManager", &vboMgr);
    
    EventListener *el = new EventListener();
    TickListener *tl = new TickListener();


    mgr->getDispatcher()->addListener("ioEvent", el);
    mgr->getDispatcher()->addListener("ioTick", tl);


    Vector3d vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[0].z = 0;


    vertices[1].x = 0;
    vertices[1].y = 1;
    vertices[1].z = 0;

    vertices[2].x = 1;
    vertices[2].y = 1;
    vertices[2].z = 0;

    Triangle t;
    t.indices[0] = 0;
    t.indices[1] = 1;
    t.indices[2] = 2;
    
    

    Mesh m;
    m.vertices = vertices;
    m.n_triangles = 1;
    m.n_vertices = 3;
    m.triangles=&t;
    

    mgr->initialize("system");
    mgr->initialize("rendering");



    vboMgr.addVbo("test", rdr.makeMeshVbo(m));
    system->eventLoop();
    mgr->destroy();

    delete el;
    delete tl;
    delete system;

}
