#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include "../events/Listener.hpp"

namespace Ballistic {
    namespace Core {
        namespace Modules {
            class ModuleManager;

            class Module : public Ballistic::Core::Events::Listener {
                /*
                 Maybe init and destroy should be invoked from module manager
                 */
            protected:
                void *initData;
                virtual void setInitData(void *initData);
                virtual void initialize() = 0;
                virtual void destroy() = 0;
                bool initialized;
                friend class ModuleManager;
            public:
                virtual void* getInitData();
                virtual bool isInitialized();
                Module();
            };
        }
    }
}



#endif

