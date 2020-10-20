#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "rt.h"
#include "ray.h"
#include "color.h"
#include "hittablelist.h"
#include "sphere.h"
#include "camera.h"

/**
 * takes path and content strings,
 * writes out to a file if possible.
 */
int WriteFile(std::string& path, std::string& content)
{
    std::ofstream fs(path, std::ofstream::out);

    if (fs.is_open()) {
        fs << content;
        fs.close();
        return 0;
    }

    return 1;
}

Color RayColor(const Ray& r, const Hittable& world, int depth)
{
    HitRecord rec;

    if (depth <= 0) {
        return Color(0.0f, 0.0f, 0.0f);
    }
    
    if (world.Hit(r, 0.001f, infinity, rec)) {
        Point3 target = rec.p + rec.normal + RandomInUnitSphere();
        return 0.5f * RayColor(Ray(rec.p, target - rec.p), world, depth - 1);
    }

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
    const float aspectRatio = 16.0f / 9.0f;
    const int width = 1000;
    const int height = static_cast<int>(width / aspectRatio);
    const int samplesPerPixel = 16;
    const int maxDepth = 50;

    std::cout << "Resolution: " << width << "x" << height << std::endl;
    std::cout << "MSAA Per-Pixel Samples: " << samplesPerPixel << std::endl;

    HittableList world;
    world.Add(std::make_shared<Sphere>(Point3(0.0f, 0.0f, -1.0f), 0.5f));
    world.Add(std::make_shared<Sphere>(Point3(0.0f, -100.5f, -1.0f), 100.0f));

    Camera cam(aspectRatio);

    // camera
    contentStream << "P3\n" << width << " " << height << "\n255\n";

    for (int j = height - 1; j >= 0; j--) {
        std::cout << "\rRender Progress: " << 100 - int(float(j) / float(height) * 100) << "%" << std::flush;
        for (int i = 0; i < width; i++) {
            Color pixelColor(0, 0 ,0);
            for (int s = 0; s < samplesPerPixel; s++) {
                float u = (i + RandomFloat()) / (width - 1);
                float v = (j + RandomFloat()) / (height - 1);
                Ray r = cam.GetRay(u, v);
                pixelColor += RayColor(r, world, maxDepth);
            }
            WriteColor(contentStream, pixelColor, samplesPerPixel);
        }
    }
    std::cout << std::endl;

    outContent = contentStream.str();

    // in case file can't be written
    if (WriteFile(outPath, outContent)) {
        std::cout << "Error: Could not open \"" << outPath << "\"." << std::endl;
        return 1;
    }

    return 0;
}
