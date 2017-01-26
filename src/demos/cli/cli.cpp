#include "../../cli/App.hpp"
#include "../../cli/Command.hpp"
#include "../../cli/Output/ConsoleOutput.hpp"
#include "../../cli/Output/NullOutput.hpp"
#include "../../cli/AppParams.hpp"



using namespace Ballistic::CLI;

using namespace Ballistic::CLI::Output;

class DemoCommand : public Command {
protected:

    virtual void setup() {
        this->setName("demo");
    }
public:

    virtual int execute() {
        this->output->write("test output\n");
    }
};

int main(int argc, char **argv) {
    ConsoleOutput output;
    
    DemoCommand demoC;

    AppParams appParams(argc, argv);
    App app(&appParams, &output);


    app.registerCommand(&demoC);

    app.run();

}
