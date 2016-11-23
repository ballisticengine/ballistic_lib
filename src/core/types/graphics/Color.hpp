#ifndef COLOR_H
#define COLOR_H

#include "types/common.hpp"



using namespace Ballistic::Core::Types;


namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {

                class Color {
                public:

                    Color() {
                    };
                    Color(scalar_t r, scalar_t g, scalar_t b, scalar_t a = 1);
                    bool operator==(const Color &color);
                    scalar_t r, g, b, a;
                };
            }
        }
    }
}

#endif