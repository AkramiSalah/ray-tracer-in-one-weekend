#pragma once
#include "../03_vector/Vec3.h"
#include "../Float.h"

class Viewport{
public:
    static constexpr Float VP_HEIGHT = Float(2.0);

    constexpr Viewport(const Point3& cam_pos, const Vec3& look_dir, Float focal_length, Float aspect_ratio){
        
        u_vec = Vec3(VP_HEIGHT * aspect_ratio, Float(0), Float(0));
        v_vec = Vec3(Float(0), -VP_HEIGHT, Float(0));  
        
        Point3 vp_center = cam_pos + focal_length*look_dir;
        top_left = vp_center - u_vec/Float(2) - v_vec/Float(2);
    }

    Point3 get_point(Float u, Float v) const {
        return top_left + u * u_vec + v * v_vec;
    }
    
private:
    Point3 top_left;
    Vec3 u_vec;
    Vec3 v_vec;
};

