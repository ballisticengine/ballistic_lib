#include <string>

namespace Ballistic {
    namespace Core {
        namespace PluginLoad {
            typedef void * lib_handle;

            class PluginHandle {
            public:
                lib_handle handle;
                std::string entry_point_name, file_name;
                void *module_class;
            };
        }
    }
}
