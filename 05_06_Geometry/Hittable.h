#include "../Float.h"
#include "../04_Rays_Camera_Background/Ray.h"
#include "Interval.h"

struct HitRecord{
    Point3 p;
    Vec3 normal;
    Float t;
};

class Hittable{
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& ray, Interval ray_t, HitRecord& rec) const = 0;
};


