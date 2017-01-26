#ifndef CLICOMMAND_HPP
#define CLICOMMAND_HPP

#include <string>
#include <map>

#include "Output/OutputInterface.hpp"
#include "Input/PositionalArg.hpp"

namespace Ballistic {
    namespace CLI {

        class App;

        class Command {
        protected:

            friend App;
            std::string name;
            Ballistic::CLI::Output::OutputInterface *output;
            virtual void setup();
            virtual void cleanup();
            std::map<size_t, Ballistic::CLI::Input::PositionalArg *> positionalArgs;
        public:
            Command();
            virtual int execute() = 0;
            virtual Command * setOutput(Ballistic::CLI::Output::OutputInterface *output);
            virtual Ballistic::CLI::Output::OutputInterface * getOutput();
            virtual std::string getName();
            virtual Command * setName(std::string name);
            virtual Command * addPositionalArg(Ballistic::CLI::Input::PositionalArg &positionalArg);
            //virtual Command * setParam(std::string name, bool required, std::string def);
        };
    }
}

#endif 

