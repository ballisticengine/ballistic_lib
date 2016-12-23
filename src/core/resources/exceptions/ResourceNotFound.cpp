#include "ResourceNotFound.hpp"

namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Exceptions {

                ResourceNotFound::ResourceNotFound(std::string file_name) :
                file_name(file_name) {

                }

                const char* ResourceNotFound::what() const throw () {
                    std::cout << "Requested resource " << this->file_name
                            << " doesn't exist" << std::endl;
                }

            }
        }
    }
}