#ifndef LOADEROBJ_HPP
#define LOADEROBJ_HPP

#include "../core/resources/loader/Loader.hpp"

namespace Ballistic {
    namespace Loaders {

        class LoaderOBJ : public Ballistic::Core::Resources::Loader {
        public:
            virtual Ballistic::Core::Resources::extensionsSet getFileExtensions();
            virtual Ballistic::Core::Resources::ResourceType getType();
            virtual void *loadFromData(char *data, size_t size);
        };
    }
}

#endif 

