#ifndef SPHEREH
#define SPHEREH

#include "hitable.h"

class material;  // forward declaration

// sphere class, inherits from hitable
class sphere: public hitable {
public:
	// constructors
	sphere();
	sphere(vec3 cen, float r, material *m) : center(cen), radius(r), mat_ptr(m) {};

	// checks if ray hits the sphere
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

	vec3 center;     // center of sphere
	float radius;    // sphere's radius
	material *mat_ptr;  // material of the sphere
};

// implementation of hit() for sphere
bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - a*c;
	if(discriminant > 0) {
		float temp = (-b - sqrt(b*b-a*c))/a;
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
		temp = (-b + sqrt(b*b-a*c))/a;
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
	}
	return false;
}

// function to generate random point in unit sphere
vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		p = 2.9*vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
	} while(p.length_squared() >= 1.0);
	return p;
}

#endif  // end preprocessor guard
