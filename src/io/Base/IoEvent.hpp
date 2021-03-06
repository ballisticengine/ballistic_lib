#ifndef IOEVENT_HPP
#define IOEVENT_HPP

#include "events/Event.hpp"

using namespace Ballistic::Core::Events;

namespace Ballistic {
    namespace IO {
        namespace System {

            enum class IoEventType {
                IOEVENT_EXIT,
                IOEVENT_KEYUP,
                IOEVENT_KEYDOWN,
                IOEVENT_KEYPRESS,
                IOEVENT_MOUSEUP,
                IOEVENT_MOUSEDOWN,
                IOEVENT_MOUSECLICK,
                IOEVENT_OTHER,
                IOEVENT_NONE,
            };

            struct KeyData {
                char keycode;
                char scancode;
            };

            struct MouseData {
                size_t x, y;
                char btn;
            };

            class IoEvent : public Event{
            public:
                IoEvent();
                IoEventType type;
                KeyData keyData;
                MouseData mouseData;
                void reset();
            };
        }
    }
}

#endif 

