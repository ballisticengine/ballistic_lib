#include "CliCommand.hpp"

namespace Ballistic {
    namespace Core {
        namespace CLI {

            void CliCommand::setup() {
                ///
            }
            
            void CliCommand::cleanup() {
                //
            }

            std::string CliCommand::getName() {
                return this->name;
            }

            CliCommand * CliCommand::setName(std::string) {
                this->name = name;
                return this;
            }
        }
    }
}