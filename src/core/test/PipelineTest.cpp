#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "pipeline/Pipeline.hpp"
#include "pipeline/Task.hpp"

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;

TEST(Functional, PipelineTest) {
    ModuleManager *m =  ModuleManager::get();
    Pipeline pp, *ppt;
    m->addModule("pipeline", &pp);
    m->initialize();
    ppt = (Pipeline *)m->getModule("pipeline");
    
    m->destroy();
    
}