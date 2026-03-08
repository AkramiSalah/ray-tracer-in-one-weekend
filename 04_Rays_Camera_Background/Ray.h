#pragma once
#include "../03_vector/Vec3.h"
#include "../Float.h"


class Ray{
public:

    Ray() = default;
    Ray(const Point3& origin, const Vec3& direction) : orig(origin), dir(direction){}
    
    ~Ray() = default;
    Ray& operator=(const Ray& other) = default;

    const Point3& origin() const{
        return orig;
    }

    const Vec3& direction() const{
        return dir;
    }

    Point3 at(Float t) const {
        return orig + t*dir;
    }

private:
    Point3 orig;
    Vec3 dir;
};
