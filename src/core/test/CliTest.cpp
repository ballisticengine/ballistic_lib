#include <iostream>
#include <vector>
#include <limits.h>
#include <gtest/gtest.h>

#include "cli/App.hpp"
#include "cli/Command.hpp"
#include "cli/Output/NullOutput.hpp"
#include "cli/AppParams.hpp"


using namespace Ballistic::Core::CLI;
using namespace Ballistic::Core::CLI::Output;

class TestCommand : public Command {
protected:

    virtual void setup() {

    }

public:

    virtual int execute() {
        return 0;
    }
};

class TestCommand2 : public Command {
protected:

    virtual void setup() {
        this->setName("test2");
    }
public:
    virtual int execute() {
        this->output->write("Some output\n");
        return 666;
    }
};

TEST(AppParams, AppTest) {

    char *argv1[] = {
        "testAppExec",
        "test",
        "otherTest"
    };

    AppParams p1(3, argv1);

    ASSERT_EQ(p1.count(), 2);
    ASSERT_EQ(p1.getExecName(), "testAppExec");
    ASSERT_EQ(p1.get(0), "test");
    ASSERT_EQ(p1.get(1), "otherTest");

    vector<std::string> prms;
    prms.push_back("a");
    prms.push_back("b");
    prms.push_back("c");

    AppParams p2("testAppExec2", prms);

    ASSERT_EQ(p2.count(), 3);
    ASSERT_EQ(p2.getExecName(), "testAppExec2");
    ASSERT_EQ(p2.get(0), "a");
    ASSERT_EQ(p2.get(1), "b");
    ASSERT_EQ(p2.get(2), "c");
}

TEST(Base, AppTest) {

    char *argv1[] = {
        "testAppExec",
        "test"
    };
    
   

    NullOutput output;
    AppParams appParams(2, argv1);
    
    App app(&appParams, &output);
    TestCommand c;
    TestCommand2 c2;
    c.setName("test");

    app.registerCommand(&c);
    app.registerCommand(&c2);
    app.run();
}