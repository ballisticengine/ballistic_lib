#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace Events {
            class Event {
            protected:
                std::string name;
                void *data;
            public:
                Event(std::string name, void *data=0);
                std::string getName();
                void *getData();
            };
        }
    }
}

#endif 

