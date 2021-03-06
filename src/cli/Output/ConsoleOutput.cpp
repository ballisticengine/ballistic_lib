#include "ConsoleOutput.hpp"

#include <iostream>

namespace Ballistic {

    namespace CLI {
        namespace Output {

            void ConsoleOutput::write(std::string text) {
                std::cout << text;
            }
        }
    }

}

