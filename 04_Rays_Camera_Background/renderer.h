#pragma once
#include "camera.h"
#include "ray.h"
#include "../03_vector/color.h"
#include <iostream>

template<typename T>
class renderer{
public:
    using Camera = camera<T>;
    using Ray = ray<T>;
    using Point3 = point3<T>;
    using Color = color<T>;

    renderer( unsigned int image_width, unsigned int image_height, T focal_length):
        image_width(image_width), image_height(image_height),
        cam(
            Point3::zero(),
            focal_length,
            T(image_width)/T(image_height)
        )
    {}

    void render(std::ostream& os) const{
        os << "P3\n" << image_width << " " << image_height << "\n255\n";
        for(int y = 0; y < image_height; y++){
            std::clog << "\rScanlines remaining: " << (image_height - y) << ' ' << std::flush;
            for (int x = 0; x < image_width; x++) {
                T u = T(x) / T(image_width - 1);
                T v = T(y) / T(image_height - 1);
                Ray r = cam.get_ray(u, v);
                Color pixel_color = ray_color(r);
                write_color(os, pixel_color);
            }
        }
        std::clog << "\rDone.                 \n";
    }

private:
    unsigned int image_width;
    unsigned int image_height;
    Camera cam;

    Color ray_color(const Ray& r) const {
        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*Color(1.0, 1.0, 1.0) + a*Color(0.5, 0.7, 1.0);
    }
};


