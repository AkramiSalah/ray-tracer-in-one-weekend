#pragma once
#include "Ray.h"
#include "Viewport.h"
#include "../Float.h"


class Camera{
public:

    static constexpr Point3 DEFAULT_POSITION = Point3(ZERO, ZERO, ZERO);
    static constexpr Float DEFAULT_FOCAL_LENGTH = ONE;
    static constexpr Float DEFAULT_ASCPECT_RATIO = Float(16)/Float(9);
    
    // Note: the aspect_ratio should be the real one, not the ideal one!
    Camera(const Point3& position, Float focal_length, Float aspect_ratio) : 
        position(position), look_dir(-Vec3::zhat()),
        vp(
            position,
            look_dir,
            focal_length,
            aspect_ratio
        ){}
    
    Camera() : Camera(DEFAULT_POSITION, DEFAULT_FOCAL_LENGTH, DEFAULT_ASCPECT_RATIO){}

    
    Ray get_ray(Float u, Float v) const{
        auto point_on_vp = vp.get_point(u,v);
        return Ray(position, unit_vector(point_on_vp - position));
    }

private:
    Point3 position;
    Vec3 look_dir;
    Viewport vp;

};   