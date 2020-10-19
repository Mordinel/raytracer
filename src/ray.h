#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    private:

    public:
        Vec3 A;
        Vec3 B;

        Ray() {}
        Ray(const Vec3& a, const Vec3& b) : A(a), B(b) {}
        Vec3 Origin() const { return A; }
        Vec3 Direction() const { return B; }
        Vec3 PointAtParameter(float t) const { return A + t * B; }

};

#endif
