#pragma once
#include "ray.h"
#include "viewport.h"

template<typename T>
class camera
{
public:
    using Point3 = point3<T>;
    using Vec3   = vec3<T>;
    using Ray    = ray<T>;
    using Viewport = viewport<T>;

    static constexpr T ZERO = T();

    static constexpr Point3 DEFAULT_POSITION = Point3(ZERO, ZERO, ZERO);
    static constexpr T DEFAULT_FOCAL_LENGTH = T(1);
    static constexpr T DEFAULT_ASCPECT_RATIO = T(16)/T(9);
    
    // Note: the aspect_ratio should be the real one, not the ideal one!
    camera(const Point3& position, T focal_length, T aspect_ratio) : 
        position(position), look_dir(-Vec3::zhat()),
        vp(
            position,
            look_dir,
            focal_length,
            aspect_ratio
        ){}
    
    camera() : camera(DEFAULT_POSITION, DEFAULT_FOCAL_LENGTH, DEFAULT_ASCPECT_RATIO){}

    
    Ray get_ray(T u, T v) const{
        auto point_on_vp = vp.get_point(u,v);
        return Ray(position, unit_vector(point_on_vp - position));
    }

private:
    Point3 position;
    Vec3 look_dir;
    Viewport vp;

};   