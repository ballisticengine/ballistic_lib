#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"
#include "pipeline/Pipeline.hpp"
#include "pipeline/Task.hpp"

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;

class TestModule : public Module {
protected:

    virtual void initialize() {
        this->test_text = "test text";
    }

    virtual void destroy() {
        this->test_text = "destroyed";
    }
    std::string test_text;
public:

    std::string getTest() {
        return this->test_text;
    }

    std::string getName() {
        return "test";
    }

};

TEST(Functional, ManagerTest) {
    ModuleManager *m = new ModuleManager();
    TestModule tm, *tmp;
    m->addModule(&tm);
    tmp = m->getModule<TestModule>("test");
    m->initialize("test");
    ASSERT_STREQ("test text", tmp->getTest().c_str());
    m->destroy("test");
    ASSERT_STREQ("destroyed", tmp->getTest().c_str());
}

TEST(Functional, PipelineTest) {
    ModuleManager *m = new ModuleManager();
    Pipeline pp, *ppt;
    m->addModule(&pp);
    m->initialize();
    ppt = m->getModule<Pipeline>("pipeline");
    
    m->destroy();
    
}