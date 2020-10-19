#ifndef CAMERA_H
#define CAMERA_H

class Camera {
    private:

    public:
        Point3 origin;
        Point3 lowerLeftCorner;
        Vec3 horizontal;
        Vec3 vertical;

        Camera(float aspectRatio)
        {
            float vpHeight = 2.0f;
            float vpWidth = aspectRatio * vpHeight;
            float focalLength = 1.0f;
            
            origin = Point3(0.0f, 0.0f, 0.0f);
            horizontal = Vec3(vpWidth, 0.0f, 0.0f);
            vertical = Vec3(0.0f, vpHeight, 0.0f);
            lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0.0f, 0.0f, focalLength);
        }

        Ray GetRay(float u, float v) const
        {
            return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
        }

};

#endif
