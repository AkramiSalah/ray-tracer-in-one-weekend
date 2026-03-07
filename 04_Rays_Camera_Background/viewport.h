#pragma once
#include "../03_vector/vec3.h"

template<typename T>
class viewport{
public:
    using Point3 = point3<T>;
    using Vec3   = vec3<T>;

    static constexpr T VP_HEIGHT = T(2.0);
    
    constexpr viewport(const Point3& cam_pos, const Vec3& look_dir, T focal_length, T aspect_ratio){
        
        u_vec = Vec3(VP_HEIGHT * aspect_ratio, T(0), T(0));
        v_vec = Vec3(T(0), -VP_HEIGHT, T(0));  
        
        Point3 vp_center = cam_pos + focal_length*look_dir;
        top_left = vp_center - u_vec/T(2) - v_vec/T(2);
    }

    Point3 get_point(T u, T v) const {
        return top_left + u * u_vec + v * v_vec;
    }
    
private:
    Point3 top_left;
    Vec3 u_vec;
    Vec3 v_vec;
};

