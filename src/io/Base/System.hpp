#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "modules/Module.hpp"
#include "IoDriver.hpp"
#include "IoEvent.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {
            class System : public Ballistic::Core::Modules::Module {
            protected:
                IoDriver *ioDriver;
                bool exit;
                virtual void initialize() = 0;
                virtual void destroy() = 0;
            public:
                System(IoDriver *ioDriver);
                virtual IoDriver *getDriver();
                virtual void eventLoop();
                virtual void shutdown();
            };
        }
    }
}

#endif 

