#include "CliApp.hpp"

#include <iostream>

using std::cout;
using std::endl;

namespace Ballistic {
    namespace Core {
        namespace CLI {

            CliApp::CliApp(int argc, const char **argv) : argc(argc), argv(argv) {
                this->parseArgv();
            }
            
            void CliApp::parseArgv() 
            {
                this->execName = this->argv[0];
                
                for(size_t i=1; i<this->argc; i++) {
                    this->params.push_back(this->argv[i]);
                }
            }

            std::string CliApp::getExecName() {
                return this->execName;
            }
            
            void CliApp::registerCommand(CliCommand *command) {
                command->setup();
                this->commands.insert(std::pair<std::string, CliCommand *>(command->getName(), command));
            }

            int CliApp::run() {
                if(params.size()==0) {
                    cout << "No params" << endl;
                    return 1;
                }
                
                std::string commandName = this->params[0];
                CliCommand *command = this->commands[commandName];
                
                if(!command) {
                    cout << "No command " + commandName + " registered." << endl; 
                    return 2;
                }
                
                command->execute();
                
                return 0;
            }

            void CliApp::cleanupCommands() {
                for (auto i : this->commands) {
                    //                    i->cleanup();
                  //NO delete here
                }
            }
        }
    }
}