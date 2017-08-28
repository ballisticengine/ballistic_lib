#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <string>
#include "../core/resources/loader/Loader.hpp"
#include "../core/resources/loader/ResourceType.hpp"

namespace Ballistic {
    namespace Loaders {
        class TextureLoader : public Ballistic::Core::Resources::Loader {
             virtual void *loadFromData(char *data, size_t size);
            virtual Ballistic::Core::Resources::extensionsSet getFileExtensions();
            virtual Ballistic::Core::Resources::ResourceType getType();
        };
    }
}

#endif 

