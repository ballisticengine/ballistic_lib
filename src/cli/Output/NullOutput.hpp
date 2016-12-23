#ifndef NULLOUTPUT_HPP
#define NULLOUTPUT_HPP

#include "OutputInterface.hpp"

namespace Ballistic {
        namespace CLI {

            namespace Output {

                class NullOutput : public OutputInterface {
                public:
                    virtual void write(std::string text);

                };
            }
        }
}

#endif 

