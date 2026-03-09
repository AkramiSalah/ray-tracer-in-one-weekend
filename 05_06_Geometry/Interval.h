#pragma once
#include "../Math.h"

struct Interval{
    Float min;
    Float max;
    
    constexpr Interval(Float min, Float max) : min(min), max(max) {}
    constexpr Interval() : Interval(+inf, -inf) {}

    constexpr Float size() const {
        return max - min;
    }

    constexpr bool contains(Float x) const {
        return  min <= x && x <= max; 
    }

    constexpr bool surrounds(Float x) const{
        return  min < x && x < max; 
    }

    static constexpr Interval EMPTY() { return Interval(+inf, -inf); }
    static constexpr Interval UNIVERSE() { return Interval(-inf, +inf); }
};




