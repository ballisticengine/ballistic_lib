#ifndef FILEDATA_HPP
#define FILEDATA_HPP

#include <string>

namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Storage {
                struct FileData {
                    std::string id;
                    char *data;
                    size_t size;
                };
            }
        }
    }
}

#endif 

