#pragma once

#include "vec3.h"
#include <iostream>



template<typename T>
constexpr double SCALE_FACTOR = static_cast<T>(255.999);

template<typename T>
using color = vec3<T>;

template<typename T>
void write_color(std::ostream& out, const color<T>& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = static_cast<int>(SCALE_FACTOR<T> * r);
    int gbyte = static_cast<int>(SCALE_FACTOR<T> * g);
    int bbyte = static_cast<int>(SCALE_FACTOR<T> * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
