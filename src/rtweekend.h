#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

inline float degreesToRadians(float degrees)
{
    return degrees * pi / 180.0f;
}

#include "ray.h"
#include "vec3.h"

#endif
