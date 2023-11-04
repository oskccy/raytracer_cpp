#ifndef HITABLEH
#define HITABLEH

#include "ray.h"  // include ray class

class material;  // forward declaration of material class

// structure to store details of ray-object intersection
struct hit_record {
	float t;           // parameter at which ray hits
	vec3 p;            // point of intersection
	vec3 normal;       // normal at point of intersection
	material *mat_ptr; // pointer to material of hit object
};

// abstract class for objects that can be hit by rays
class hitable {
public:
	// virtual function to determine if object is hit by ray between t_min and t_max
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif  // end preprocessor guard
