#include "WithWD.hpp"


namespace Ballistic {
    namespace Helpers {

        std::string WithWD::getWD() {
            return this->wd;
        }

        void WithWD::setWD(std::string wd) {
            this->wd = wd;
        }
    }
}

