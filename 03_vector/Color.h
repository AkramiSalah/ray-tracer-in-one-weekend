#pragma once

#include "Vec3.h"
#include "../Float.h"
#include <iostream>
#include <algorithm>



using Color = Vec3;

inline void write_color(std::ostream& out, const Color& pixel_color){
    static constexpr Float SCALE_FACTOR = Float(255.999);
    auto r = std::clamp(pixel_color.x(), ZERO, ONE);
    auto g = std::clamp(pixel_color.y(), ZERO, ONE);
    auto b = std::clamp(pixel_color.z(), ZERO, ONE);

    int rbyte = static_cast<int>(SCALE_FACTOR * r);
    int gbyte = static_cast<int>(SCALE_FACTOR * g);
    int bbyte = static_cast<int>(SCALE_FACTOR * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
