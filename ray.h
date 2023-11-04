#ifndef RAYH
#define RAYH

#include "vec3.h"  // 3D vector class

// ray class definition
class ray {
public:
    // default constructor
    ray() {}

    // constructor: init with origin 'a' and direction 'b'
    ray(const vec3& a, const vec3& b) {
        A = a;
        B = b;
    }

    // get ray's origin
    vec3 origin() const {
        return A;
    }

    // get ray's direction
    vec3 direction() const {
        return B;
    }

    // compute point along ray for param t
    vec3 point_at_parameter(float t) const {
        return A + t * B;
    }

    vec3 A, B;  // origin and direction of ray
};

#endif  // end preprocessor guard
