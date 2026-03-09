#include "../Float.h"
#include "../04_Rays_Camera_Background/Ray.h"
#include "Interval.h"

struct HitRecord{
    Point3 p;
    Vec3 normal;
    Float t;
    bool front_face;

    void set_face_normal(const Ray& ray, const Vec3& outward_normal){
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.
        
        front_face = dot(ray.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }

};

class Hittable{
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& ray, Interval ray_t, HitRecord& rec) const = 0;
};


