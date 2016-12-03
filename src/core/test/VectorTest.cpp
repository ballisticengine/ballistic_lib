#include <limits.h>
#include <gtest/gtest.h>

#include "types/spatial/Vector3d.hpp"
using namespace Ballistic::Core::Types::Spatial;

TEST(Construct, VectorTest) {
    Vector3d v;
    ASSERT_EQ(v.x, 0);
    ASSERT_EQ(v.y, 0);
    ASSERT_EQ(v.z, 0);
    Vector3d v2(1, 2, 3);
    ASSERT_EQ(v2.x, 1);
    ASSERT_EQ(v2.y, 2);
    ASSERT_EQ(v2.z, 3);

}

TEST(UnitOpBasic, VectorTest) {
    Vector3d resv;
    Vector3d v1(1, 2, 3), v2(2, 4, 6);

    resv = v1 + 4;
    ASSERT_EQ(resv.x, 5);
    ASSERT_EQ(resv.y, 6);
    ASSERT_EQ(resv.z, 7);

    resv = v1 - 4;
    ASSERT_EQ(resv.x, -3);
    ASSERT_EQ(resv.y, -2);
    ASSERT_EQ(resv.z, -1);

    resv = v2 / 2;

    ASSERT_EQ(resv.x, 1);
    ASSERT_EQ(resv.y, 2);
    ASSERT_EQ(resv.z, 3);

    resv = v1 * 4;

    ASSERT_EQ(resv.x, 4);
    ASSERT_EQ(resv.y, 8);
    ASSERT_EQ(resv.z, 12);

    resv = -v1;

    ASSERT_EQ(resv.x, -1);
    ASSERT_EQ(resv.y, -2);
    ASSERT_EQ(resv.z, -3);
}

TEST(DotProduct, VectorTest) {
    Vector3d a(3, 2, -4),
            b(5, -1, 2),
            x(1, 1, 1),
            y(-1, -1, -1);
    ASSERT_EQ(5, a.dotProduct(b));
    ASSERT_EQ(-3, x.dotProduct(y));

}

TEST(CrossProduct, VectorTest) {

    Vector3d a(-1, 7, 4), b(-5, 8, 4);
    
    Vector3d cpV = a.crossProduct(b);
    //(-4, -16, 27)
}