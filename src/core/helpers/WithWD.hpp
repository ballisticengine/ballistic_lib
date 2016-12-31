#ifndef WITHWD_HPP
#define WITHWD_HPP

#include <string>

namespace Ballistic {
    namespace Helpers {

        class WithWD {
        protected:
            std::string wd;
        public:
            virtual std::string getWD();
            virtual void setWD(std::string wd);


        };
    }
}

#endif

