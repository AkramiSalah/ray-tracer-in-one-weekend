#pragma once
#include "Hittable.h"
#include "../03_vector/Vec3.h"
#include "../Float.h"

class Sphere : public Hittable{
public:
    Sphere(const Point3& center,  Float radius) : center(center), radius(radius){}

    bool hit(const Ray& ray, Interval ray_t, HitRecord& hit_rec) const override{
        Vec3 origin_to_center = center - ray.origin();
        auto a = ray.direction().length_squared();
        auto h = dot(ray.direction(), origin_to_center);
        auto c = origin_to_center.length_squared() - radius*radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant);

        auto root = (h - sqrtd)/a;
        if (!ray_t.surrounds(root)){
            root = (h + sqrtd)/a;
            if(!ray_t.surrounds(root)){
                return false;
            }
        }

        hit_rec.t = root;
        hit_rec.p = ray.at(hit_rec.t);
        Vec3  outward_normal = (hit_rec.p - center)/radius;
        hit_rec.set_face_normal(ray, outward_normal);

        return true;
    }

private:
    Point3 center;
    Float radius;
};