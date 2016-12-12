#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "cli/CliApp.hpp"
#include "cli/CliCommand.hpp"

using namespace Ballistic::Core::CLI;


class TestCommand : public CliCommand {
protected:
    virtual void setup() {
       
    }

public:
    virtual int execute() {
        return 0;
    }
};



TEST(Base, AppTest) {
    
    char *argv1[] = {
        "testAppExec",
        "test"
    };
    
    CliApp *app = new CliApp(2, (const char**)argv1);
    TestCommand *c = new TestCommand();
    c->setName("test");
    
    app->registerCommand(c);
    app->run();
}