#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <fstream>
#include <cmath>

class Vec3 {
    private:

    public:
        float e[3];

        Vec3() : e{0.0f,0.0f,0.0f} {}
        Vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

        float x() const { return e[0]; }
        float y() const { return e[1]; }
        float z() const { return e[2]; }

        Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
        float operator[](int i) const { return e[i]; }
        float& operator[](int i) { return e[i]; }

        Vec3& operator+=(const Vec3& v)
        {
           this->e[0] += v.e[0]; 
           this->e[1] += v.e[1]; 
           this->e[2] += v.e[2]; 
           return *this;
        }

        Vec3& operator*=(const float t)
        {
           this->e[0] *= t; 
           this->e[1] *= t; 
           this->e[2] *= t; 
           return *this;
        }

        Vec3& operator/=(const float t)
        {
           return *this *= 1/t;
        }

        float Length() const
        {
            return std::sqrt(this->LengthSquared());
        }

        float LengthSquared() const
        {
            return 
                this->e[0] * this->e[0] +
                this->e[1] * this->e[1] +
                this->e[2] * this->e[2];
        }

};

using Point3 = Vec3;
using Color = Vec3;

inline std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    return os << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(
            v1.e[0] + v2.e[0],
            v1.e[1] + v2.e[1],
            v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(
            v1.e[0] - v2.e[0],
            v1.e[1] - v2.e[1],
            v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
    return Vec3(
            v1.e[0] * v2.e[0],
            v1.e[1] * v2.e[1],
            v1.e[2] * v2.e[2]);
}

inline Vec3 operator*(float t, const Vec3& v)
{
    return Vec3(
            t * v.e[0],
            t * v.e[1],
            t * v.e[2]);
}

inline Vec3 operator*(const Vec3& v, float t)
{
    return t * v;
}

inline Vec3 operator/(Vec3 v, float t)
{
    return (1.0f/t) * v;
}

inline float dot(const Vec3& v1, const Vec3& v2)
{
    return 
        v1.e[0] * v2.e[0] +
        v1.e[1] * v2.e[1] +
        v1.e[2] * v2.e[2];
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2)
{
    return Vec3(
            v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
            v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
            v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline Vec3 UnitVector(Vec3 v)
{
    return v / v.Length();
}

#endif
