#include <iostream>
#include "modules/ModuleManager.hpp"
#include "types/graphics/Mesh.hpp"
#include "types/graphics/Texture.hpp"
#include "types/spatial/Vector3d.hpp"
#include "SDL/SDLIoDriver.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"
#include "../../rendering/renderers/GL/GLRenderer.hpp"
#include "../../rendering/renderingPipeline/Tasks/BeginFrameTask.hpp"
#include "../../rendering/renderingPipeline/Tasks/EndFrameTask.hpp"
#include "../../scene/rendering/RenderSceneTask.hpp"
#include "types/graphics/materials/Material.hpp"
#include "types/graphics/materials/SimpleColorMaterial.hpp"
#include "types/graphics/materials/TextureMaterial.hpp"
#include "types/graphics/Color.hpp"
#include "EventListener.hpp"
#include "TickListener.hpp"
#include "../../rendering/VBO/VboManager.hpp"
#include "FrameTask.hpp"

#include "../../core/resources/ResourceManager.hpp"
#include "../../core/resources/ResourceHandle.hpp"
#include "../../core/resources/storage/FilesystemStorageHandler.hpp"
#include "../../loaders/LoaderXML.hpp"
#include "../../loaders/TextureLoader.hpp"
#include "../../core/resources/loader/Results.hpp"
#include "../../scene/Node.hpp"
#include "../../scene/MeshNode.hpp"
#include "../../scene/TransformNode.hpp"
#include "../../core/calc/MatrixCalculator.hpp"

using namespace std;
using namespace Ballistic::Core::Modules;
using namespace Ballistic::IO::SDL;
using Ballistic::Core::Types::Graphics::Mesh;
using Ballistic::Core::Types::Graphics::Triangle;
using Ballistic::Core::Types::Graphics::Texture;
using Ballistic::Core::Types::Spatial::Vector3d;
using Ballistic::Rendering::Vbo::VboManager;
using namespace Ballistic::Core::Types::Graphics::Materials;
using Ballistic::Core::Types::Graphics::Color;
using namespace Ballistic::Core::Resources;
using namespace Ballistic::Core::Resources::Storage;
using namespace Ballistic::Loaders;
using namespace Ballistic::Scene;
using namespace Ballistic::Core::Calc;

int main() {
    FilesystemStorageHandler fs;
    fs.setWD("../src/test/data");
    ResourceManager resMan(&fs);

    LoaderXML loaderXML;
    TextureLoader textureLoader;

    resMan.getLoader().registerStaticPlugin("loaderXML", &loaderXML);
    resMan.getLoader().registerStaticPlugin("textureLoader", &textureLoader);

    ModuleManager *mgr = ModuleManager::get();

    SDLIoDriver *io = new SDLIoDriver();

    System *system = new System(io, mgr->getDispatcher());
    Ballistic::Rendering::Renderers::GLRenderer rdr;
    Ballistic::Rendering::Pipeline::RenderingPipeline rpl(&rdr);
    VboManager vboMgr;

    Ballistic::Rendering::Pipeline::BeginFrameTask bft;
    Ballistic::Rendering::Pipeline::EndFrameTask eft;
    Ballistic::Scene::RenderSceneTask rst;

    MatrixCalculator mc;

    FrameTask ft;

    rpl.addTask("begin", &bft);
    rpl.addTask("sg", &rst);
    // rpl.addTask("frame", &ft);
    rpl.addTask("end", &eft);


    mgr->addModule("system", system);
    mgr->addModule("rendering", &rpl);
    mgr->addModule("vboManager", &vboMgr);
    mgr->addModule("resourceManager", &resMan);



    mgr->initialize("system");
    mgr->initialize("rendering");

    ResourceHandle rH = resMan.get("untitled.xml", "meshAndMaterial");
    MeshAndMaterialResult *res = (MeshAndMaterialResult *) rH.getData();
    Mesh *m = res->mesh;
    Material *mtl = res->material;
    TextureMaterial *tmtl = (TextureMaterial *) mtl->getMaterialData();
    ResourceHandle tH = resMan.get("tex.gif", "texture");

    rdr.setupTexture((Texture *) tH.getData());

    TransformNode scene, identityNode;


    
    scene.translate(Vector3d(0, 0, -10));


    Ballistic::Rendering::Vbo::Vbo *vboV = rdr.makeVbo(*m, *tmtl);

    MeshNode model(m, tmtl, vboV), model2(m, tmtl, vboV), model3(m, tmtl, vboV);
    model.translate(Vector3d(0, 0, 0));
    scene.addChild(&model);
    model2.translate(Vector3d(0, -5, -10));
    scene.addChild(&model2);
    model3.translate(Vector3d(4, 0, 0));
    model2.addChild(&model3);
    
    rst.setRootNode(&scene);

    scene.update();
    

    EventListener *el = new EventListener(&scene);
    TickListener *tl = new TickListener();


    mgr->getDispatcher()->addListener("ioEvent", el);
    mgr->getDispatcher()->addListener("ioTick", tl);

    system->eventLoop();
    mgr->destroy();

    delete m;
    delete el;
    delete tl;
    delete system;

}
