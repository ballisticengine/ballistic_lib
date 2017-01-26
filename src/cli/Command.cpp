#include "Command.hpp"

namespace Ballistic {

    namespace CLI {
        using Ballistic::CLI::Output::OutputInterface;

        Command::Command() {
            this->output = 0;
        }

        void Command::setup() {
            ///
        }

        void Command::cleanup() {
            ///
        }

        std::string Command::getName() {
            return this->name;
        }

        Command * Command::setName(std::string name) {
            this->name = name;
            return this;
        }

        Command * Command::setOutput(OutputInterface *output) {
            this->output = output;
            return this;

        }

        OutputInterface * Command::getOutput() {
            return this->output;
        }

        Command * Command::addPositionalArg(Ballistic::CLI::Input::PositionalArg &positionalArg) {
            this->positionalArgs[positionalArg.getPosition()] = &positionalArg;

            return this;
        }

    }
}