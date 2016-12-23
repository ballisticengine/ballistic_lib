#include <string>

namespace Ballistic {
    namespace Core {
        namespace DynamicLoad {
            typedef void * lib_handle;

            class Plugin {
            public:
                lib_handle handle;
                std::string entry_point_name, file_name;
                void *module_class;
            };
        }
    }
}
