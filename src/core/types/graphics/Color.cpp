#include "Color.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {

                Color::Color(scalar_t r, scalar_t g, scalar_t b, scalar_t) : r(r), g(g), b(b), a(a) {

                }

                bool Color::operator==(const Color &color) {
                    return (r == color.r && g == color.g && b == color.b && a == color.a);
                }
            }
        }
    }
}
