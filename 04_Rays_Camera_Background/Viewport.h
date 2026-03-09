#pragma once
#include "../03_vector/Vec3.h"
#include "../Float.h"

class Viewport{
public:
    static constexpr Float VP_HEIGHT = Float(2.0);

    Viewport(const Point3& cam_pos, const Vec3& look_dir, Float focal_length, Float aspect_ratio){
        
        u_vec = Vec3(VP_HEIGHT * aspect_ratio, ZERO, ZERO);
        v_vec = Vec3(ZERO, -VP_HEIGHT, ZERO);  
        
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

