#include "./LoaderOBJ.hpp"

namespace Ballistic {
    namespace Loaders {

        Ballistic::Core::Resources::extensionsSet LoaderOBJ::getFileExtensions() {
            Ballistic::Core::Resources::extensionsSet exts;
            exts.insert("obj");
            return exts;
        }

       Ballistic::Core::Resources::ResourceType LoaderOBJ::getType() {

        }

        void * LoaderOBJ::loadFromData(char *data, size_t size) {

        }

    }
}