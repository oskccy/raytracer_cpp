#ifndef CAMERAH
#define CAMERAH

#include "ray.h"  // include ray class

// camera class definition
class camera {
public:
    // default constructor: sets up camera with a hard-coded configuration
    camera() {
        lower_left_corner = vec3(-2.0, -1.0, -1.0);
        horizontal = vec3(4.0, 0.0, 0.0);
        vertical = vec3(0.0, 2.0, 0.0);
        origin = vec3(0.0, 0.0, 0.0);
    }

    // generate a ray from the camera's origin passing through point (u,v) on viewport
    ray get_ray(float u, float v) {
        return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    }

    vec3 lower_left_corner, horizontal, vertical, origin;  // camera parameters
};

#endif  // end preprocessor guard
