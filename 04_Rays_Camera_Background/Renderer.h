#pragma once
#include "Camera.h"
#include "Ray.h"
#include "../03_vector/Color.h"
#include "../Float.h"
#include "../CONSTANTS.h"
#include "../05_06_Geometry/HittableList.h"
#include <iostream>

class Renderer{
public:

    Renderer( unsigned int image_width, unsigned int image_height, Float focal_length):
        image_width(image_width), image_height(image_height),
        cam(
            Point3::zero(),
            focal_length,
            Float(image_width)/Float(image_height)
        )
    {}

    Renderer(unsigned int image_size, Float focal_length) : Renderer(image_size, image_size, focal_length){}

    Renderer() : Renderer(DEFAULT_IMAGE_SIZE, DEFAULT_FOCAL_LENGTH){}
    
    void setWorldGeometryPtr(HittableList const* wg_ptr){
        worldGeometry = wg_ptr;
    }

    void render(std::ostream& os) const{
        os << "P3\n" << image_width << " " << image_height << "\n255\n";
        for(int y = 0; y < image_height; y++){
            std::clog << "\rScanlines remaining: " << (image_height - y) << ' ' << std::flush;
            for (int x = 0; x < image_width; x++) {
                Float u = Float(x) / Float(image_width - 1);
                Float v = Float(y) / Float(image_height - 1);
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
    HittableList const* worldGeometry;

    Color ray_color(const Ray& r) const {
        HitRecord rec;
        if(worldGeometry->hit(r, Interval(0, inf), rec)){
            return 0.5 * (rec.normal + Color(1,1,1));
        }

        Vec3 unit_direction = unit_vector(r.direction());
        auto a = Float(0.5)*(unit_direction.y() + ONE);
        return (ONE-a)*Color(ONE, ONE, ONE) + a*Color(Float(0.5), Float(0.7), ONE);
    }
};


