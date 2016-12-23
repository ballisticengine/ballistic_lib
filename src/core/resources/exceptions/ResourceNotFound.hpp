#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

namespace Ballistic {
    namespace Core {
        namespace Resources {
            namespace Exceptions {

                class ResourceNotFound : public std::exception {
                protected:
                    std::string file_name;
                public:
                    ResourceNotFound(std::string file_name);
                    virtual const char* what() const throw ();

                    ~ResourceNotFound() throw () {
                    }

                };
            }
        }
    }
}



#endif

