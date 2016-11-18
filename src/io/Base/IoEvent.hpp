#ifndef IOEVENT_HPP
#define IOEVENT_HPP

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
                IOEVENT_OTHER
            };

            struct KeyData {
                char keycode;
                char scancode;
            };

            struct MouseData {
                size_t x, y;
                char btn;
            };

            struct IoEvent {
                IoEventType type;
            };
        }
    }
}

#endif 

