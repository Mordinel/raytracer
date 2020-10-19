#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    private:

    public:
        Point3 origin;
        Vec3 direction;

        Ray() {}
        Ray(const Point3& origin, const Vec3& direction) : origin(origin), direction(direction) {}
        Point3 Origin() const { return origin; }
        Vec3 Direction() const { return direction; }
        Vec3 At(float t) const 
        {
            return origin + t * direction;
        }

};

#endif
