#ifndef TEXTURE_HPP
#define TEXTURE_HPP
namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Graphics {
                struct Texture {
                    void *pixels;
                    size_t width, height, size, bpp;
                    
                };
            }
        }
    }
}


#endif 

