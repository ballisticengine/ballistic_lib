#ifndef BEGINFRAMETASK_HPP
#define BEGINFRAMETASK_HPP

#include "pipeline/Task.hpp"


class BeginFrameTask : public Ballistic::Core::Pipeline::Task {
protected:
    virtual void run(Ballistic::Core::Pipeline::Pipeline *p);
};

#endif 

