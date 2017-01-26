#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>


#include "../core/types/spatial/Matrix.hpp"
#include "../core/types/spatial/Vector3d.hpp"
#include "../core/calc/MatrixCalculator.hpp"

using Ballistic::Core::Types::Spatial::Matrix;
using Ballistic::Core::Types::Spatial::Matrix4;
using Ballistic::Core::Types::Spatial::Vector3d;
using Ballistic::Core::Types::scalar_t;
using namespace Ballistic::Core::Calc;

TEST(Matrix, InitTest) {
    Matrix m1(2, 2);

    ASSERT_EQ(m1.get(0, 0), 0.0f);
    ASSERT_EQ(m1.get(0, 1), 0.0f);
    ASSERT_EQ(m1.get(1, 0), 0.0f);
    ASSERT_EQ(m1.get(1, 1), 0.0f);

    scalar_t mData[4] = {
        0.0f, 1.0f,
        2.0f, 3.0f
    };

    Matrix m2(2, 2);
    m2.set(mData);

    ASSERT_EQ(m2.get(0, 0), 0.0f);
    ASSERT_EQ(m2.get(0, 1), 1.0f);
    ASSERT_EQ(m2.get(1, 0), 2.0f);
    ASSERT_EQ(m2.get(1, 1), 3.0f);

}

TEST(Matrix, EqualsOpeartor) {
    Matrix m1(2, 2), m2(2, 2), m3(2, 2), m4(1, 1);

    scalar_t mData[4] = {0.0f, 1.0f, 2.0f, 3.0f};

    m1.set(mData);
    m2.set(mData);

    ASSERT_EQ(m1 == m2, true);
    ASSERT_EQ(m1 == m3, false);
    ASSERT_EQ(m1 == m4, false);


}

TEST(Matrix, AssignOperator) {
    Matrix m1(2, 2), m2(2, 2);
    scalar_t mData[4] = {0.0f, 1.0f, 2.0f, 3.0f};
    m1.set(mData);

    m2 = m1;

    ASSERT_EQ(m1 == m2, true);

}

TEST(Matrix, IdentityTest) {
    scalar_t identity[9] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    MatrixCalculator mc;
    Matrix m(3, 3), identityMatrix(3, 3);

    identityMatrix.set(identity);

    scalar_t *d = identityMatrix.get();

    /*
     Preset identity
     */
    ASSERT_EQ(identityMatrix.get(0, 0), 1.0f);
    ASSERT_EQ(identityMatrix.get(1, 0), 0.0f);
    ASSERT_EQ(identityMatrix.get(2, 0), 0.0f);

    ASSERT_EQ(identityMatrix.get(0, 1), 0.0f);
    ASSERT_EQ(identityMatrix.get(1, 1), 1.0f);
    ASSERT_EQ(identityMatrix.get(2, 1), 0.0f);

    ASSERT_EQ(identityMatrix.get(0, 2), 0.0f);
    ASSERT_EQ(identityMatrix.get(1, 2), 0.0f);
    ASSERT_EQ(identityMatrix.get(2, 2), 1.0f);

    mc.identity(&m);

    ASSERT_EQ(m.get(0, 0), 1.0f);
    ASSERT_EQ(m.get(1, 0), 0.0f);
    ASSERT_EQ(m.get(2, 0), 0.0f);

    ASSERT_EQ(m.get(0, 1), 0.0f);
    ASSERT_EQ(m.get(1, 1), 1.0f);
    ASSERT_EQ(m.get(2, 1), 0.0f);

    ASSERT_EQ(m.get(0, 2), 0.0f);
    ASSERT_EQ(m.get(1, 2), 0.0f);
    ASSERT_EQ(m.get(2, 2), 1.0f);

    ASSERT_EQ(identityMatrix == m, true);

}

TEST(Matrix, MatrixMultiplyTest) {
    MatrixCalculator mc;

    Matrix m1(2, 2), m2(2, 2), m3(2, 2);

    scalar_t a[4] = {1.0f, 2.0f, 3.0f, 4.0f},
    b[4] = {5.0f, 6.0f, 7.0f, 8.0f}
    ;

    m1.set(a);
    m2.set(b);

    mc.multiply(&m3, &m1, &m2);


    ASSERT_EQ(m3.get(0, 0), 19.0f);
    ASSERT_EQ(m3.get(0, 1), 22.0f);
    ASSERT_EQ(m3.get(1, 0), 43.0f);
    ASSERT_EQ(m3.get(1, 1), 50.0f);

}

TEST(Matrix, TranslationTest) {
    MatrixCalculator mc;

    Vector3d tv(10, 20, 30);
    Matrix m1(4, 4);

    mc.identity(&m1);

    mc.translate(&m1, tv);


    ASSERT_EQ(m1.get(0, 0), 1);
    ASSERT_EQ(m1.get(1, 0), 0);
    ASSERT_EQ(m1.get(2, 0), 0);
    ASSERT_EQ(m1.get(3, 0), 10);

    ASSERT_EQ(m1.get(0, 1), 0);
    ASSERT_EQ(m1.get(1, 1), 1);
    ASSERT_EQ(m1.get(2, 1), 0);
    ASSERT_EQ(m1.get(3, 1), 20);

    ASSERT_EQ(m1.get(0, 2), 0);
    ASSERT_EQ(m1.get(1, 2), 0);
    ASSERT_EQ(m1.get(2, 2), 1);
    ASSERT_EQ(m1.get(3, 2), 30);

    ASSERT_EQ(m1.get(0, 3), 0);
    ASSERT_EQ(m1.get(1, 3), 0);
    ASSERT_EQ(m1.get(2, 3), 0);
    ASSERT_EQ(m1.get(3, 3), 1);
}