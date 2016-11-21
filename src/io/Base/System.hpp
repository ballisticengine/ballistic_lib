#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "modules/Module.hpp"
#include "events/Dispatcher.hpp"
#include "IoDriver.hpp"
#include "IoEvent.hpp"
using namespace Ballistic::Core::Modules;

namespace Ballistic {
    namespace IO {
        namespace System {

            class System : public Module {
            protected:
                IoDriver *ioDriver;
                Ballistic::Core::Events::Dispatcher *dispatcher;
                bool exit;
                virtual void initialize();
                virtual void destroy();
            public:

                System(IoDriver* ioDriver, Ballistic::Core::Events::Dispatcher *dispatcher) 
                : Module(), ioDriver(ioDriver), dispatcher(dispatcher) {

                }
                IoDriver *getDriver();
                void eventLoop();
                void shutdown();
            };
        }
    }
}

#endif 

