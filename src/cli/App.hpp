#ifndef CLIAPP_HPP
#define CLIAPP_HPP

#include <map>
#include <string>
#include <vector>

#include "Command.hpp"
#include "Output/OutputInterface.hpp"
#include "AppParams.hpp"

namespace Ballistic {
        namespace CLI {

            class App {
                /*
                 * TODO:
                 * default command [when no params provided]
                 */

            protected:
                int argc;
                const char **argv;
                std::map<std::string, Command *> commands;
                AppParams *params;
                Ballistic::CLI::Output::OutputInterface *output;
            public:
                App(AppParams *appParams, Ballistic::CLI::Output::OutputInterface *output);

                virtual void registerCommand(Command *command);

                

                virtual int run();

                virtual void cleanupCommands();
            };
        }
}




#endif 

