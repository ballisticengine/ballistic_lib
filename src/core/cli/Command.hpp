#ifndef CLICOMMAND_HPP
#define CLICOMMAND_HPP

#include <string>

#include "Output/OutputInterface.hpp"

namespace Ballistic {
    namespace Core {
        namespace CLI {

            class App;

            class Command {
            protected:

                friend App;
                std::string name;
                 Ballistic::Core::CLI::Output::OutputInterface *output;
                virtual void setup();
                virtual void cleanup();

            public:

                virtual int execute() = 0;
                virtual void setOutput(Ballistic::Core::CLI::Output::OutputInterface *output);
                virtual Ballistic::Core::CLI::Output::OutputInterface * getOutput();
                virtual std::string getName();
                virtual Command * setName(std::string name);
                virtual Command * setParam(std::string name, bool required, std::string def);
            };
        }
    }
}

#endif 

