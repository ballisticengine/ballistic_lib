#include "PositionalArg.hpp"

namespace Ballistic {
    namespace CLI {
        namespace Input {

            PositionalArg::PositionalArg(std::string name, size_t position) 
            : name(name), position(position), value("") 
            {
                
            }

            std::string PositionalArg::getName() {
                return this->name;
            }

            std::string PositionalArg::getValue() {
                return this->value;
            }
            
            size_t PositionalArg::getPosition() {
                return this->position;
            }
        }
    }
}
