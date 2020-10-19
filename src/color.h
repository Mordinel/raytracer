#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

void WriteColor(std::ostream& os, Color pixelColor)
{
    os << static_cast<int>(255.999 * pixelColor.x()) << " "
       << static_cast<int>(255.999 * pixelColor.y()) << " "
       << static_cast<int>(255.999 * pixelColor.z()) << "\n";
}

#endif
