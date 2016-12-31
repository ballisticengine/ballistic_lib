#include "FilesystemStorageHandler.hpp"

#include <cstdio>
#include <iostream>

namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Storage {

                FileData
                FilesystemStorageHandler::getResource(std::string resourceId) {
                    using namespace std;
                    FileData fileData;

                    std::string fn = this->wd+"/"+resourceId.c_str(); 
                    
                    FILE *f = fopen(fn.c_str(), "rb");

                    if (!f) {
                        std::cout << "fn not found: " << fn << std::endl;
                    }
                    //TODO: throw exception if not f
                    
                    fseek(f, 0, SEEK_END);

                    fileData.size = ftell(f);
                    fileData.data = new char[fileData.size];
                    fileData.id = resourceId;
                    
                    rewind(f);
                    fread(fileData.data, sizeof (char), fileData.size, f);

                    fclose(f);

                    return fileData;
                }
            }
        }
    }
}

