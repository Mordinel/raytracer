#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include <memory>
#include <vector>

#include "hittable.h"

class HittableList : public Hittable {
    private:

    public:
        std::vector<std::shared_ptr<Hittable>> objects;

        HittableList() {}
        HittableList(std::shared_ptr<Hittable> object) { Add(object); }

        void Clear() { objects.clear(); }
        void Add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

        virtual bool Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const override;
};

bool HittableList::Hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const
{
    HitRecord tmpRec;
    bool hitAnything = false;
    float closestSoFar = t_max;

    for (const auto& object : objects) {
        if (object->Hit(r, t_min, closestSoFar, tmpRec)) {
            hitAnything = true;
            closestSoFar = tmpRec.t;
            rec = tmpRec;
        }
    }

    return hitAnything;
}

#endif
