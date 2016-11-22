#ifndef FRAMETASK_HPP
#define	FRAMETASK_HPP

#include "../../rendering/renderingPipeline/RenderingTask.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"


using namespace Ballistic::Rendering::Pipeline;

  
class FrameTask : public RenderingTask {
  
protected:
    virtual void run(RenderingPipeline *p);
};

#endif	

