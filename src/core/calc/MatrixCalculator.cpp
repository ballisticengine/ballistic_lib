#include "MatrixCalculator.hpp"

namespace Ballistic {
    namespace Core {
        namespace Calc {

            void MatrixCalculator::identity(Matrix *m) {
                for (size_t c = 0; c < m->cols; c++) {
                    m->set(c, c, 1);
                }
            }

            void MatrixCalculator::translate(Matrix *m, Vector3d vector) {
                ///https://www.gamedev.net/topic/335211-glloadmatrix-doesnt-work/
                //OpenGL is column-major, is it possible you're trying to use row-major? Just a guess... 
                //Thats exactly it. 
                // TODO: convert to col-major.
                Matrix tm(m->cols, m->rows);
                this->identity(&tm);
                tm.set(3, 0, vector.x);
                tm.set(3, 1, vector.y);
                tm.set(3,2, vector.z);
                tm.set(3,3, 1);
                
                this->multiply(m, m, &tm);

            }

            void MatrixCalculator::multiply(Matrix *target, Matrix *a, Matrix *b) {
                Matrix m(target->getCols(), target->getRows());

                for (size_t i = 0; i < m.getCols(); i++) {
                    for (size_t j = 0; j < m.getCols(); j++) {
                        for (size_t k = 0; k < m.getCols(); k++) {
                            m.set(i, j, m.get(i, j) + a->get(i, k) * b->get(k, j));
                        }
                    }
                }

                *target = m;

            }
        }
    }
}
