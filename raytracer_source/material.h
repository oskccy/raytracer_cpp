#ifndef MATERIALH
#define MATERIALH

// forward declaration for hit_record
struct hit_record;

// abstract material class
class material {
public:
	// virtual function to determine how rays scatter when they hit an object
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};

// lambertian material (diffuse)
class lambertian : public material {
public:
	// constructor: init with albedo (color)
	lambertian(const vec3& a) : albedo(a) {}

	// how lambertian surfaces scatter light
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		scattered = ray(rec.p, target-rec.p);
		attenuation = albedo;
		return true;
	}

	vec3 albedo;  // material color
};

// metal material
class metal : public material {
public:
	// constructor: init with albedo and fuzziness
	metal(const vec3& a, float f) : albedo(a) {
		if(f < 1) fuzz = f; else fuzz = 1;
	}

	// how metal surfaces scatter light
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
		vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere());
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}

	vec3 albedo;  // material color
	int fuzz;     // how fuzzy reflections are (0 = perfect mirror, >0 = rougher)
};

#endif  // end preprocessor guard
