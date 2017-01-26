#ifndef FRAMETASK_HPP
#define FRAMETASK_HPP

#include "../../rendering/renderingPipeline/RenderingTask.hpp"
#include "../../rendering/renderingPipeline/RenderingPipeline.hpp"
#include "../../core/types/spatial/Matrix.hpp"


using namespace Ballistic::Rendering::Pipeline;
using namespace Ballistic::Core::Types::Spatial;

class FrameTask : public RenderingTask {
protected:
    Matrix4 m;

    virtual void run(RenderingPipeline *p);

public:
    FrameTask();
};

#endif 

