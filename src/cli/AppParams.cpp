#include "AppParams.hpp"


namespace Ballistic {
    namespace CLI {

        AppParams::AppParams(size_t count, char **params) {

            this->execName = params[0];

            for (size_t i = 1; i < count; i++) {
                this->params.push_back(params[i]);
            }
        }

        AppParams::AppParams(std::string execName, std::vector<std::string>params)
        : execName(execName), params(params) {

        }

        std::string AppParams::getExecName() {
            return this->execName;
        }

        size_t AppParams::count() {
            return this->params.size();
        }

        std::string AppParams::get(size_t index) {
            return this->params[index];
        }
    }
}