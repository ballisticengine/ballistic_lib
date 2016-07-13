#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace Modules {
            class ModuleManager;

            class Module {
                /*
                 Maybe init and destroy should be invoked from module manager
                 */
            protected:
                void *initData;
                virtual void setInitData(void *initData);
                virtual void initialize() = 0;
                virtual void destroy() = 0;
                friend class ModuleManager;
            public:
                virtual std::string getName() = 0;
                virtual void* getInitData();
            };
        }
    }
}



#endif

