#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "ray.h"
#include "color.h"

/**
 * takes path and content strings,
 * writes out to a file if possible.
 */
int writeFile(std::string& path, std::string& content)
{
    std::ofstream fs(path, std::ofstream::out);

    if (fs.is_open()) {
        fs << content;
        fs.close();
        return 0;
    }

    return 1;
}

Vec3 RayColor(const Ray& r)
{
    Vec3 UnitDirection = UnitVector(r.Direction());
    float t = 0.5f * (UnitDirection.y() + 1.0f);
    return (1.0f - t) * Color(1.0f, 1.0f, 1.0f) + t * Color(0.5f, 0.7f, 1.0f);
}

int main(int argc, char* argv[])
{
    // args
    if (argc != 2) {
        std::cerr << "Usage: " << std::string(argv[0]) << " <outfile>" << std::endl;
        return 1;
    }

    std::string outContent;
    std::string outPath(argv[1]);

    std::ostringstream contentStream;

    // image
    const float aspectRatio = 16.0f / 10.0f;
    const int width = 1920;
    const int height = static_cast<int>(width / aspectRatio);

    // camera
    float vpHeight = 2.0f;
    float vpWidth = aspectRatio * vpHeight;
    float focalLength = 1.0f;

    contentStream << "P3\n" << width << " " << height << "\n255\n";

    Point3 origin(0.0f, 0.0f, 0.0f);
    Vec3 horizontal(vpWidth, 0.0f, 0.0f);
    Vec3 vertical(0.0f, vpHeight, 0.0f);
    Point3 lowerLeftCorner = origin - horizontal / 2 - vertical - Vec3(0.0f, 0.0f, focalLength);

    for (int j = height - 1; j >= 0; j--) {
        std::cout << "\rScanlines remaining: " << j << " " << std::flush;
        for (int i = 0; i < width; i++) {
            float u = float(i) / float(width - 1);
            float v = float(j) / float(height - 1);
            Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
            Color col = RayColor(r);
            WriteColor(contentStream, col);
        }
    }
    std::cout << "\r" << std::endl;

    outContent = contentStream.str();

    // in case file can't be written
    if (writeFile(outPath, outContent)) {
        std::cout << "Error: Could not open \"" << outPath << "\"." << std::endl;
        return 1;
    }

    return 0;
}
