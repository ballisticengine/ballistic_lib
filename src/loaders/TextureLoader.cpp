#include "TextureLoader.hpp"

#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../core/types/graphics/Texture.hpp"


namespace Ballistic {
    namespace Loaders {

        using Ballistic::Core::Types::Graphics::Texture;

        void *TextureLoader::loadFromData(char *data, size_t size) {

            Texture *texture = new Texture();

            SDL_RWops* rwops = SDL_RWFromMem(data, size);
            SDL_Surface * surface = IMG_Load_RW(rwops, 0), *convSurf;

            convSurf = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ABGR8888, 0);
            texture->bpp = convSurf->pitch / convSurf->h;
            texture->width = convSurf->w;
            texture->height = convSurf->h;

            size_t texSize = texture->height * convSurf->pitch;
            
            texture->pixels = new char[texSize];

            std::memcpy(texture->pixels, convSurf->pixels, texSize);
            
            SDL_FreeSurface(surface);
            SDL_FreeSurface(convSurf);

            return texture;

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

        Ballistic::Core::Resources::ResourceType TextureLoader::getType() {
             return Ballistic::Core::Resources::RESOURCE_TEXTURE;
        }


    }
}

