#ifndef INPUTPARAM_HPP
#define INPUTPARAM_HPP

#include <string>

namespace Ballistic {
    namespace CLI {
        namespace Input {

             class App;
            
            class PositionalArg {
            protected:
                friend App;
                virtual void setValue(std::string value);
                
                std::string name, value;
                size_t position;
            public:
                PositionalArg(std::string name, size_t position);
                virtual std::string getName();
                virtual std::string getValue();
                virtual size_t getPosition();
            };
        }
    }

}


#endif 

