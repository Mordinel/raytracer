#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

void WriteColor(std::ostream& os, Color pixelColor, int samplesPerPixel)
{
    float r = pixelColor.x();
    float g = pixelColor.y();
    float b = pixelColor.z();

    float scale = 1.0f / samplesPerPixel;

    r *= scale;
    g *= scale;
    b *= scale;

    os << static_cast<int>(256 * Clamp(r, 0.0f, 0.999)) << " "
       << static_cast<int>(256 * Clamp(g, 0.0f, 0.999)) << " "
       << static_cast<int>(256 * Clamp(b, 0.0f, 0.999)) << "\n";
}

#endif
