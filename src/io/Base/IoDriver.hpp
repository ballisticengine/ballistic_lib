#ifndef IODRIVER_HPP
#define IODRIVER_HPP

#include <string>
#include "IoEvent.hpp"

namespace Ballistic {
    namespace IO {
        namespace System {
            class System;
            
            class IoDriver {
            protected:
                virtual void transform(void *rawEvent, Ballistic::IO::System::IoEvent *event)=0;
                virtual bool pollEvent(void *event)=0; 
                virtual void * createEvent()=0;
                virtual void initialize(void *params) = 0;
                virtual void destroy() = 0;   
                virtual void flush() = 0;
                friend class System;
            public:
                virtual void setWindowTitle(std::string) {};
                virtual void setResolution(size_t width, size_t height){};
                virtual void setFullscreen(bool fullscreen) {};
                virtual std::string getWindowTitle() {return "";};
                virtual size_t* getResolution() {return 0;};
                virtual bool getFullscreen() {return false;};
            };
        }
    }
}

#endif

