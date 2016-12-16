#ifndef OUTPUTINTERFACE_HPP
#define OUTPUTINTERFACE_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace CLI {
            namespace Output {

                class OutputInterface {
                public:
                    //                virtual void setParam(std::string key, void *value) {
                    //                    
                    //                }
                    //                virtual void getParam(std::string key, void *value) {
                    //                    
                    //                }
                    virtual void write(std::string text) = 0;
                };
            }
        }
    }
}

#endif

