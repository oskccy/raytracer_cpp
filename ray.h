#include "vec3.h" // include "vec3.h" to access the vec3 class

class ray {
    // math function like P(x) = (A + x*B)
public:
    ray() {} // default constructor for a ray object

    // parameterized constructor that takes two vec3 objects: origin + direction
    ray(const vec3& a, const vec3 b) { A = a; B = b; }

    // accessor to get components of the ray
    vec3 origin() const { return A; }       // origin point of the ray
    vec3 direction() const { return B; }    // direction of the ray

    // compute point on the ray at parameter t
    vec3 point_at_parameter(float t) const { return A + t * B; }

    vec3 A, B;  // two vec3 objects representing the origin and direction of the ray
};
