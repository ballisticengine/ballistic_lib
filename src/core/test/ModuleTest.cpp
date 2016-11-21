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


};

TEST(Functional, ManagerTest) {
    ModuleManager *m =  ModuleManager::get();
    TestModule *tm=new TestModule(), *tmp;
    m->addModule("test", tm);
    tmp = (TestModule*)m->getModule("test");
    m->initialize("test");
    m->initialize("test");
    ASSERT_STREQ("test text", tmp->getTest().c_str());
    m->destroy("test");
    ASSERT_STREQ("destroyed", tmp->getTest().c_str());
}

