#pragma once
#include <limits>
#include "Float.h"

// Constants
constexpr Float inf = std::numeric_limits<Float>::infinity();
constexpr Float pi = Float(3.1415926535897932385);

// Utility Functions
constexpr Float degrees_to_radians(Float degrees) {
    return  pi * degrees / Float(180.0);
}