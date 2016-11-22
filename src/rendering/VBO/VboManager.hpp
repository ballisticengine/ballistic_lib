#ifndef VBOMANAGER_HPP
#define	VBOMANAGER_HPP

#include <string>
#include <map>
#include "modules/Module.hpp"

namespace Ballistic {
    namespace Rendering {
        namespace Vbo {

            class VboManager : public Ballistic::Core::Modules::Module {
            protected:
                virtual void initialize();
                virtual void destroy();
                std::map<std::string, void *> vboMap;
            public:
                void addVbo(std::string id, void * vboId);
                void * getVbo(std::string id);

            };
        }

    };
}



#endif	

