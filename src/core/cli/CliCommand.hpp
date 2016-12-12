#ifndef CLICOMMAND_HPP
#define CLICOMMAND_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace CLI {
        
            class CliApp;
            
            class CliCommand {
            protected:
                friend CliApp;
                std::string name;
                virtual void setup();
                virtual void cleanup();
                
            public:
                
                virtual int execute()=0;
                
                virtual std::string getName();
                virtual CliCommand * setName(std::string);
            };
        }
    }
}

#endif 

