#include "System.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {

            System::System(IoDriver* ioDriver) {
                this->ioDriver = ioDriver;
                this->exit = false;
            }

            void System::initialize() {
                this->ioDriver->initialize(0);
            }

            void System::destroy() {
                this->ioDriver->destroy();
            }

            void System::eventLoop() {
                void *rawEvent;
                IoEvent event;
                while (!this->exit) {
                    rawEvent = this->ioDriver->poolEvent();
                    this->ioDriver->transform(rawEvent, &event);
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

