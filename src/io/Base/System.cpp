#include "System.hpp"
#include "events/Event.hpp"

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
                void *rawEvent = this->ioDriver->createEvent();
                IoEvent event;
                Ballistic::Core::Events::Event tickEvent("ioTick");

                while (!this->exit) {
                    while (this->ioDriver->pollEvent(rawEvent)) {
                        this->ioDriver->transform(rawEvent, &event);
                        this->dispatcher->dispatch(&event);
                        event.reset();

                    }
                    this->dispatcher->dispatch(&tickEvent);
                    this->ioDriver->flush();
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

