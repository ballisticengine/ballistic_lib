#include "Loader.hpp"
#include <cstdio>

namespace Ballistic {
    namespace Core {
        namespace Resources {

            bool Loader::handlesEntension(std::string extension) {
                extensionsSet exts = this->getFileExtensions();
                if (exts.find(extension) != exts.end()) {
                    return true;
                }
                return false;
            }

            void Loader::addDependency(std::string file_name, void **target, std::string type) {
                Dependency dep;
                dep.file_name = file_name;
                dep.target = target;
                dep.type = type;
                dependencies.push_back(dep);
            }

            dependencyVector Loader::getDependencies() {
                return this->dependencies;
            }

            void Loader::cleanDependencies() {
                this->dependencies.clear();
            }

            void *Loader::load(std::string file_name) {
                using namespace std;
                FILE* f = fopen(file_name.c_str(), "r");


                fseek(f, 0, SEEK_END);
                size_t size = ftell(f);

                char* buffer = new char[size];

                rewind(f);

                fread(buffer, sizeof (char), size, f);

                void * data = this->loadFromData(buffer, size);
                
                delete buffer;
                
                return data;
            }

            size_t Loader::getPriority() {
                return 0;
            }

           
        }
    }
}