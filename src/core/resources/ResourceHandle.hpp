#ifndef RESOURCEHANDLE_HPP
#define RESOURCEHANDLE_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace Resources {
            
            /*
             TODO: make storage result class
             */
            class ResourceHandle {
            protected:
                void *data;
                size_t refCount;
                std::string type, id;
                
            public:
                ResourceHandle(std::string id, std::string type, void *data);
                //TODO: link and unlink shouldn't be public
                virtual std::string getId();
                virtual void link();
                virtual void unlink();
                virtual size_t getRefCount();
                virtual void * getData();
                
                virtual ~ResourceHandle();
   
            };
        }
    }
}

#endif

