#include "types/spatial/Matrix.hpp"

#include <iostream>

using namespace std;

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Spatial {

                Matrix::Matrix(size_t cols, size_t rows) : cols(cols), rows(rows) {
                    this->data = new scalar_t[cols * rows];
                    for (size_t i = 0; i < cols * rows; i++) {
                        this->data[i] = 0;
                    }
                }

                Matrix::Matrix(size_t cols, size_t rows, scalar_t *data) {
                    Matrix(cols, rows);
                    this->set(data);
                }

                Matrix & Matrix::operator=(const Matrix & m) {
                    this->cols = m.cols;
                    this->rows = m.rows;

                    if (this->data) {
                        delete this->data;

                    }

                    this->data = new scalar_t[cols * rows];

                    for (size_t i = 0; i < cols * rows; i++) {
                        this->data[i] = m.data[i];
                    }

                    return *this;
                }

                size_t Matrix::getCols() {
                    return this->cols;

                }

                size_t Matrix::getRows() {
                    return this->rows;
                }

                bool Matrix::operator==(const Matrix & m) {
                    if (m.cols != this->cols || m.rows != this->rows) {
                        return false;
                    }


                    for (size_t c = 0; c<this->cols; c++) {
                        for (size_t r = 0; r<this->rows; r++) {
                            if (m.get(c, r) != get(c, r)) {
                                return false;
                            }

                        }
                    }

                    return true;
                }

                void Matrix::set(size_t row, size_t col, scalar_t value) {

                    this->data[row * this->cols + col] = value;
                }

                void Matrix::set(scalar_t *data) {
                    //this->data = data;
                    memcpy((void *) this->data, (const void *) data, sizeof (scalar_t) * cols * rows);
                }

                scalar_t Matrix::get(size_t row, size_t col) const {

                    return this->data[row * this->cols + col];
                }

                scalar_t *Matrix::get() const {
                    return this->data;
                }

                Matrix::~Matrix() {

                    delete this->data;

                }

                Matrix::operator scalar_t*() {
                    return this->data;
                }

                void Matrix::setIdentity() {
                    for (size_t c = 0; c<this->cols; c++) {
                        //  cout << cols << ", " << rows << ", " << c << endl;
                        this->set(c, c, 1);
                    }
                }

                //// Matrix4 ////

                Matrix4::Matrix4() : Matrix(4, 4) {

                }
            }
        }
    }
}

