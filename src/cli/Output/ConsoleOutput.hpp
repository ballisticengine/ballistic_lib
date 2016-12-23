#ifndef CONSOLEOUTPUT_HPP
#define CONSOLEOUTPUT_HPP

#include "OutputInterface.hpp"

namespace Ballistic {

    namespace CLI {
        namespace Output {

            class ConsoleOutput : public OutputInterface {
            public:
                virtual void write(std::string text);

            };
        }
    }

}

#endif 

