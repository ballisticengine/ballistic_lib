#include "App.hpp"

#include <iostream>

using std::cout;
using std::endl;

namespace Ballistic {
        namespace CLI {

            App::App(AppParams *appParams, Ballistic::CLI::Output::OutputInterface *output) 
            : params(appParams), output(output) {
                
            }
            
            

          
            
            void App::registerCommand(Command *command) {
                command->setup();
                if(!command->getOutput()) {
                    command->setOutput(this->output);
                }
                this->commands.insert(std::pair<std::string, Command *>(command->getName(), command));
            }

            int App::run() {
                if(this->params->count()==0) {
                    this->output->write("No params\n");
                    return 1;
                }
                
                std::string commandName = this->params->get(0);
                Command *command = this->commands[commandName];
                
                if(!command) {
                    this->output->write("No command"+commandName+" registered.\n");
                    //cout << "No command " + commandName + " registered." << endl; 
                    return 2;
                }
                
                command->execute();
                
                return command->execute();
            }

            void App::cleanupCommands() {
                for (auto i : this->commands) {
                    //                    i->cleanup();
                  //NO delete here
                }
            }
        }
}