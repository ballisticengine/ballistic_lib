#ifndef CLIAPP_HPP
#define CLIAPP_HPP

#include <map>
#include <string>
#include <vector>

#include "CliCommand.hpp"

namespace Ballistic {
    namespace Core {
        namespace CLI {

            class CliApp {
            protected:
                int argc;
                const char **argv;
                std::map<std::string, CliCommand *> commands;
                std::vector<std::string> params;
                std::string execName;
                virtual void parseArgv();
                
            public:
                CliApp(int argc, const char **argv);
                
                virtual void registerCommand(CliCommand *command);
                
                virtual std::string getExecName();
                
                virtual int run();
                
                virtual void cleanupCommands();
            };
        }
    }
}




#endif 

