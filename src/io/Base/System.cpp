#include "System.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {

            

            void System::initialize() {
               
                this->ioDriver->initialize(0);
                this->exit = false;
            }

            void System::destroy() {
                this->ioDriver->destroy();
            }

            void System::eventLoop() {
                void *rawEvent;
                IoEvent event;
                while (!this->exit) {
                    rawEvent = this->ioDriver->poolEvent();
                    if (rawEvent) {
                        this->ioDriver->transform(rawEvent, &event);
                        this->dispatcher->dispatch(&event);
                    }
                }
            }

            void System::shutdown() {
                this->exit = true;
            }

            IoDriver *System::getDriver() {
                return this->ioDriver;
            }
        }
    }
}

