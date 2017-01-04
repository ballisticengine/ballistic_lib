#include "IoEvent.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {

            IoEvent::IoEvent() : Event("ioEvent") {

            }

            void IoEvent::reset() {
                this->type = IoEventType::IOEVENT_NONE;
            }
        }
    }
}