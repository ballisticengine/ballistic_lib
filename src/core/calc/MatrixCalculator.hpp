#ifndef MATRIXCALCULATOR_HPP
#define MATRIXCALCULATOR_HPP

#include "../types/spatial/Matrix.hpp"
#include "../types/spatial/Vector3d.hpp"


/*
 TODO: 
 * maybe make it into matrix factory and simplify matrix class (or make it array)
 * or NOT - calculator might be CPU for GL/DX or GPU one, its not related
 */
namespace Ballistic {
    namespace Core {
        namespace Calc {
            using Ballistic::Core::Types::Spatial::Matrix;
            using Ballistic::Core::Types::Spatial::Vector3d;

            class MatrixCalculator {
            public:
                virtual void identity(Matrix *m);
                virtual void translate(Matrix *m, Vector3d vector);
                virtual void rotateX(Matrix *target, scalar_t angle);
                virtual void multiply(Matrix *target, Matrix *a, Matrix *b);


            };
        }
    }

}



#endif
