#include "Vector3d.hpp"

namespace Ballistic {
    namespace Core {
        namespace Types {
            namespace Spatial {

                Vector3d::Vector3d() {
                    x = y = z = 0;
                }

                Vector3d::Vector3d(const Vector3d &v) {
                    x = v.x;
                    y = v.y;
                    z = v.z;
                }

                Vector3d::Vector3d(scalar_t x, scalar_t y, scalar_t z) {
                    this->x = x;
                    this->y = y;
                    this->z = z;
                }
                
                scalar_t Vector3d::ifZero(scalar_t value) {
                    if (value > 0) {
                        return 1;
                    } else if (value < 0) {
                        return -1;
                    }
                    return 0;

                }

                Vector3d Vector3d::unit() {
                    Vector3d v;
                    v = *this;
                    v.x = ifZero(v.x);
                    v.y = ifZero(v.y);
                    v.z = ifZero(v.z);
                    return v;
                }

                
                std::ostream & Vector3d::operator<<(std::ostream & ostr) {
                    ostr << this->x << ", " << this->y << ", " << this->z;
                    return ostr;
                }

                Vector3d Vector3d::crossProduct(const Vector3d & b) {

                    Vector3d a = *this, v = a;

                    v.x = a.y * b.z - a.z * b.y;
                    v.y = a.z * b.x - a.x * b.z;
                    v.z = a.x * b.y - a.y * b.x;

                    return v;
                }

                Vector3d & Vector3d::operator=(const Vector3d &v) {
                    x = v.x;
                    y = v.y;
                    z = v.z;
                    return *this;
                }

                scalar_t Vector3d::length() {
                    scalar_t length = (scalar_t) sqrt(x * x + y * y + z * z);
                    return length;
                }

                Vector3d Vector3d::normalize() {
                    Vector3d v = *this;
                    if (length() != 0) {
                        v.x /= length();
                        v.y /= length();
                        v.z /= length();
                    } else {
                        v.x = 0;
                        v.y = 0;
                        v.z = 0;
                    }
                    return v;
                }

                scalar_t Vector3d::dotProduct(const Vector3d & b) {
                    scalar_t dp = x * b.x + y * b.y + z * b.z;
                    return dp;
                }

                Vector3d Vector3d::operator+(const Vector3d &b) {
                    Vector3d v;
                    v.x = this->x + b.x;
                    v.y = this->y + b.y;
                    v.z = this->z + b.z;
                    return v;
                }

                Vector3d Vector3d::operator+(const scalar_t val) {
                    return Vector3d(x + val, y + val, z + val);
                }

                Vector3d Vector3d::operator-(const Vector3d &b) {
                    Vector3d v;
                    v.x = this->x - b.x;
                    v.y = this->y - b.y;
                    v.z = this->z - b.z;
                    return v;
                }

                Vector3d Vector3d::operator-(const scalar_t val) {
                    return Vector3d(x - val, y - val, z - val);

                }

                Vector3d Vector3d::operator/(const scalar_t val) {
                    return Vector3d(x / val, y / val, z / val);
                }

                Vector3d Vector3d::operator/(const Vector3d &b) {
                    Vector3d v;
                    v.x = this->x / b.x;
                    v.y = this->y / b.y;
                    v.z = this->z / b.z;
                    return v;
                }

                Vector3d Vector3d::operator*(const Vector3d &b) {
                    Vector3d v;
                    v.x = x * b.x;
                    v.y = y * b.y;
                    v.z = z * b.z;
                    return v;
                }

                Vector3d Vector3d::operator*(const scalar_t a) {
                    return Vector3d(x*a, y*a, z * a);
                }

                Vector3d Vector3d::operator-() {
                    return Vector3d(-x, -y, -z);
                }

                const bool Vector3d::operator==(const Vector3d &v) {
                    return v.x == x && v.y == y && v.z == z;
                }
            }
        }
    }
}

