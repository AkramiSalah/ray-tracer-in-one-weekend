#pragma once
#include "vec3.h"

template<typename T>
class viewport{
public:
    using Point3 = point3<T>;
    using Vec3   = vec3<T>;

    constexpr viewport(const Point3& top_left, const Vec3& u, const Vec3& v) :
        top_left(top_left), u_vec(u), v_vec(v){}

    Point3 get_point(T u, T v) const {
        return top_left + u * u_vec + v * v_vec;
    }
    
private:
    Point3 top_left;
    Vec3 u_vec;
    Vec3 v_vec;
};

