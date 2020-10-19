#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <random>
#include <limits>
#include <memory>

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

inline float degreesToRadians(float degrees)
{
    return degrees * pi / 180.0f;
}

inline float randomFloat() {
    static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float randomFloat(float min, float max) {
    return min + (max - min) * randomFloat();
}

#include "ray.h"
#include "vec3.h"

#endif
