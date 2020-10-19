#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    float t;
    bool frontFace;

    inline void setFaceNormal(const Ray& r, const Vec3& outwardNormal) {
        frontFace = dot(r.Direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable {
    private:

    public:
        virtual bool Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const = 0;
};

#endif
