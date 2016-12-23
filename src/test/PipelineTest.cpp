#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "pipeline/Pipeline.hpp"
#include "pipeline/Task.hpp"

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;

class TestTask : public Task {
protected:
    void run(void *pipeline) {
        
    }
};

TEST(Functional, PipelineTest) {
    ModuleManager *m =  ModuleManager::get();
    Pipeline pp, *ppt;
    m->addModule("pipeline", &pp);
    m->initialize();
    ppt = (Pipeline *)m->getModule("pipeline");
    
    TestTask tt;
    
    pp.addTask("test", &tt);
    
    pp.runAll();
    
    m->destroy();
    
}