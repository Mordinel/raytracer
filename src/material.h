#ifndef MATERIAL_H
#define MATERIAL_H

#include "rt.h"

struct HitRecord;

class Material {
    private:
    
    public:
        virtual bool Scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material {
    private:

    public:
        Color albedo;

        Lambertian(const Color& a) : albedo(a) {}

        virtual bool Scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override
        {
            Vec3 scatterDirection = rec.normal + RandomUnitVector();
            scattered = Ray(rec.p, scatterDirection);
            attenuation = albedo;
            return true;
        }
};

class Metal : public Material {
    private:

    public:
        Color albedo;
        float fuzz;

        Metal(const Color& a, float f) : albedo(a), fuzz(f < 1 ? f : 1) {}

        virtual bool Scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const override
        {
            Vec3 reflected = Reflect(UnitVector(r_in.Direction()), rec.normal);
            scattered = Ray(rec.p, reflected + fuzz * RandomInUnitSphere());
            attenuation = albedo;
            return (dot(scattered.Direction(), rec.normal) > 0);
        }
};

#endif
