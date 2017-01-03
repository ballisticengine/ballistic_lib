#include "AbstractBuilder.hpp"

#include <iterator>
#include <algorithm>

namespace Ballistic {
    namespace Core {
        namespace Builders {
            using Ballistic::Core::Types::Spatial::Vector3d;
            
            size_t AbstractBuilder::addIfNotExists(Vector3d v, std::vector<Vector3d> &vectors) {
                size_t index = findVector(v, vectors);
                if (index == -1) {
                    vectors.push_back(v);
                    return vectors.size() - 1;
                }

                return index;
            }

            size_t AbstractBuilder::findVector(Vector3d & v, std::vector<Vector3d> & vectors) {
                auto it = std::find(vectors.begin(), vectors.end(), v);
                if (it == vectors.end()) {
                    return -1;
                } else {
                    return distance(vectors.begin(), it);
                }
            }
        }
    }
}