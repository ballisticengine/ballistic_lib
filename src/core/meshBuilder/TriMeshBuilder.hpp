#ifndef TRIMESHBUILDER_HPP
#define TRIMESHBUILDER_HPP
#include "AbstractMeshBuilder.hpp"
namespace Ballistic {
    namespace Core {
        namespace MeshBuilder {
            class TriMeshBuilder : public AbstractMeshBuilder {
            public:
                TriMeshBuilder();    
                virtual void * build();
            };
        }
    }
}

#endif 

