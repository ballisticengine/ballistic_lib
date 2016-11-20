#include "Event.hpp"

namespace Ballistic {
    namespace Core {
        namespace Events {

            Event::Event(std::string name, void *data) : name(name), data(data) {

            }

            std::string Event::getName() {
                return this->name;
            }

            void * Event::getData() {
                return this->data;
            }
        }
    }
}
