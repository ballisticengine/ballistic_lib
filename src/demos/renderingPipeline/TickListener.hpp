#ifndef TICKHANDLER_HPP
#define TICKHANDLER_HPP
#include "events/Listener.hpp"
#include "modules/ModuleManager.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"

using namespace Ballistic::Core::Events;
using Ballistic::Rendering::Pipeline::RenderingPipeline;

class TickListener : public Listener {
protected:
    Ballistic::Core::Modules::ModuleManager *mgr;
    RenderingPipeline *pipeline;
public:
    TickListener();  
    virtual void processEvent(void *e);
};

#endif 

