#include "Sphere.h"
#include "../04_Rays_Camera_Background/Renderer.h"
#include "../Float.h"
#include "../03_vector/Vec3.h"
/*
    this is an example small program to show curretn progress.
    its not meant to be pretty, not meant to be safe,
    its only meant to show a working prototype.
*/

int main(){
    static HittableList worldGeomtry;
    static Renderer renderer = Renderer();

    worldGeomtry.add(
        std::make_shared<Sphere>(
            Point3(ZERO,ZERO,-ONE),
            Float(0.5)
        )
    );

    worldGeomtry.add(
        std::make_shared<Sphere>(
            Point3(ZERO,Float(-100.5),-ONE),
            Float(100)
        )
    );

    renderer.setWorldGeometryPtr(&worldGeomtry);

    renderer.render(std::cout);
    return 0;
}