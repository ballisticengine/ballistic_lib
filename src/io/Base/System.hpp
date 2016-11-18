#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "modules/Module.hpp"
#include "IoDriver.hpp"
#include "IoEvent.hpp"
using namespace Ballistic::Core::Modules;

namespace Ballistic {
    namespace IO {
        namespace System {
            class System : public Module {
            protected:
                IoDriver *ioDriver;
                bool exit;
                virtual void initialize();
                virtual void destroy();
            public:
                
                virtual IoDriver *getDriver();
                virtual void eventLoop();
                virtual void shutdown();
            };
        }
    }
}

#endif 

