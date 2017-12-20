#ifndef LOADEROBJ_HPP
#define LOADEROBJ_HPP

#include "../core/resources/loader/Loader.hpp"
#include "../core/types/common.hpp"
#include <vector>
#include <string>

namespace Ballistic {
    namespace Loaders {

        class LoaderOBJ : public Ballistic::Core::Resources::Loader {
        protected:
            std::vector<std::string> makeLines(char *data);
            int * splitFace(char *faceStr);
        public:
            virtual Ballistic::Core::Resources::extensionsSet getFileExtensions();
            virtual Ballistic::Core::Resources::ResourceType getType();
            virtual void *loadFromData(char *data, size_t size);
        };
    }
}

#endif 

