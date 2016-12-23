#include "Command.hpp"

namespace Ballistic {

    namespace CLI {
        using Ballistic::CLI::Output::OutputInterface;

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

        void Command::setOutput(OutputInterface *output) {
            this->output = output;
        }

        OutputInterface * Command::getOutput() {
            return this->output;
        }

    }
}