#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "material.h"

class Sphere : public Hittable {
    private:

    public:
        Point3 center;
        float radius;
        std::shared_ptr<Material> mat_ptr;

        Sphere() {}
        Sphere(Point3 cen, float r, std::shared_ptr<Material> m) : center(cen), radius(r), mat_ptr(m) {};

        virtual bool Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const override;
};

bool Sphere::Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const
{
    Vec3 oc = r.Origin() - center;
    float a = r.Direction().LengthSquared();
    float halfb = dot(oc, r.Direction());
    float c = oc.LengthSquared() - radius * radius;
    float discriminant = halfb * halfb - a * c;

    if (discriminant > 0) {
        float root = std::sqrt(discriminant);

        float tmp = (-halfb - root) / a;
        if (tmp < t_max && tmp > t_min) {
            rec.t = tmp;
            rec.p = r.At(rec.t);
            Vec3 outwardNormal = (rec.p - center) / radius;
            rec.setFaceNormal(r, outwardNormal);
            rec.mat_ptr = mat_ptr;
            return true;
        }

        tmp = (-halfb + root) / a;
        if (tmp < t_max && tmp > t_min) {
            rec.t = tmp;
            rec.p = r.At(rec.t);
            Vec3 outwardNormal = (rec.p - center) / radius;
            rec.setFaceNormal(r, outwardNormal);
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    
    return false;
}

#endif
