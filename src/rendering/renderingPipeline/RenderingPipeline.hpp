#ifndef RENDERINGPIPELINE_HPP
#define RENDERINGPIPELINE_HPP

#include "pipeline/Pipeline.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Pipeline {

            class RenderingPipeline : public Ballistic::Core::Pipeline::Pipeline {
            protected:
                virtual void initialize();
                virtual void destroy();
                
            public:
                //virtual void addDefaultTasks();

            };
        }
    }
}



#endif

