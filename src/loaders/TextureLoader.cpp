#include "TextureLoader.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../core/types/graphics/Texture.hpp"


namespace Ballistic {
    namespace Loaders {

        void *TextureLoader::loadFromData(char *data, size_t size) {
            SDL_RWops* rwops = SDL_RWFromMem(data, size);
            SDL_Surface * surface = IMG_Load_RW(rwops, 0);
            

        }

        Ballistic::Core::Resources::extensionsSet TextureLoader::getFileExtensions() {
            Ballistic::Core::Resources::extensionsSet exts;
            exts.insert("gif");
            exts.insert("jpg");
            exts.insert("jpeg");
            exts.insert("png");
            exts.insert("bmp");
            return exts;
        }

        std::string TextureLoader::getType() {
            return "texture";
        }


    }
}

