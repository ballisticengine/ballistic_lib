#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>
#include <iostream>
#include "types/common.hpp"



namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Spatial {
                using namespace Ballistic::Core::Types;
                class Vector3d {
                protected:
                    scalar_t ifZero(scalar_t value);
                public:
                    scalar_t x, y, z;
                    Vector3d(scalar_t x, scalar_t y, scalar_t z);
                    Vector3d(const Vector3d &v);
                    Vector3d();
                    virtual Vector3d & operator=(const Vector3d &v);
                    virtual const bool operator==(const Vector3d &v);
                    virtual Vector3d unit();
                    virtual Vector3d normalize();
                    scalar_t length();
                    Vector3d crossProduct(const Vector3d & b);
                    scalar_t dotProduct(const Vector3d & b);
                    Vector3d operator^(const Vector3d &b);

                    Vector3d operator+(const Vector3d &b);
                    Vector3d operator+(const scalar_t val);

                    Vector3d operator-(const Vector3d &b);
                    Vector3d operator-(const scalar_t val);
                    Vector3d operator-();

                    Vector3d operator/(const scalar_t val);
                    Vector3d operator/(const Vector3d &b);

                    Vector3d operator*(const Vector3d &b);
                    Vector3d operator*(const scalar_t a);

                    

                    virtual std::ostream & operator<<(std::ostream & ostr);
                };
            }
        }
    }
}

#endif

