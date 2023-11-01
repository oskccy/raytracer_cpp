#include <iostream>
#include <fstream> // for writing to file
#include "ray.h" // ray clss & vec3 util

bool hit_sphere(const vec3 center, float radius, const ray& r) {
	vec3 oc = r.origin()-center;
	float a = dot(r.direction(),r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - 4*a*c;
	return (discriminant > 0);
}

vec3 sphere;
float sphere_radius;

vec3 color(const ray& r) {
	if(hit_sphere(sphere, sphere_radius, r)) {return vec3(1,0,0);}
	vec3 unit_dir = unit_vector(r.direction());
	float t = 0.5*(unit_dir.y() + 1.0);
	return (1.0-t)*vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);
}

int main() {
	sphere = vec3(0,0,-1);
	sphere_radius = 0.5;

	// dimensions for PPM file reading
	int width = 800;
	int height = 400;
	// rendering bucket is a PPM rendering file
    std::ofstream rendering_bucket;
    rendering_bucket.open("render.ppm");

	rendering_bucket << "P3\n" << width << " " << height << "\n255\n";

	vec3 lower_left_corner(-2.0,-1.0,-1.0);
	vec3 horizontal(4.0,0.0,0.0);
	vec3 vertical(0.0,2.0,0.0);
	vec3 origin(0.0,0.0,0.0);

	for(int y=height-1; y>=00; y--) {
		for(int x=0; x<width; x++) {
			
			float u = float(x) / float(width);
			float v = float(y) / float(height);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 col = color(r);

			// accessing vec3 for ir,ig & ib
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			// directly writing to the render.ppm file
			rendering_bucket << ir << " " << ig << " " << ib << "\n";
		}
	}
}