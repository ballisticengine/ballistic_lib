#ifndef CLIAPPPARAMS_HPP
#define CLIAPPPARAMS_HPP

#include <string>
#include <vector>

namespace Ballistic {

    namespace CLI {

        class AppParams {
        protected:
            std::string execName;
            std::vector<std::string> params;
        public:
            AppParams(int count, char**params);
            AppParams(std::string execName, std::vector<std::string>params);
            virtual std::string getExecName();
            virtual size_t count();
            virtual std::string get(size_t index);
        };
    }
}


#endif 

