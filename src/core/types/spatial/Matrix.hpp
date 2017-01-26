#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstring>
#include "types/common.hpp"


using namespace std;
using namespace Ballistic::Core::Types;


namespace Ballistic {
    namespace Core {
        namespace Calc {
            class MatrixCalculator;
        }
    }

}

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Spatial {
                
                class Matrix { //TODO: static (class) setCaulculator and object operators using it
                protected:
                    friend Ballistic::Core::Calc::MatrixCalculator;
                    size_t cols, rows;
                    scalar_t *data;
                public:
                    Matrix(size_t cols, size_t rows);
                    Matrix(size_t cols, size_t rows, scalar_t *data);
                    virtual void set(size_t row, size_t col, scalar_t value);
                    virtual void set(scalar_t *data);
                    virtual scalar_t get(size_t row, size_t col) const;
                    virtual scalar_t *get() const;
                    virtual void setIdentity();
                    virtual bool operator==(const Matrix &m);
                    virtual Matrix & operator=(const Matrix & m);
                    virtual size_t getCols();
                    virtual size_t getRows();
                    //    virtual Matrix & operator*(Matrix &matrix);
                    virtual ~Matrix();
                    virtual operator scalar_t*();
                };

                class Matrix4 : public Matrix {
                public:
                    Matrix4();
                };
            }
        }
    }
}



#endif

