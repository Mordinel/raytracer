#ifndef RT_H
#define RT_H

#include <cmath>
#include <random>
#include <limits>
#include <memory>

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

inline float DegreesToRadians(float degrees)
{
    return degrees * pi / 180.0f;
}

inline float RandomFloat() {
    static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float RandomFloat(float min, float max) {
    return min + (max - min) * RandomFloat();
}

inline float Clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#include "ray.h"
#include "vec3.h"

#endif
