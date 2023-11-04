#include <iostream>
#include "sphere.h"          // sphere class
#include "hitable_list.h"    // list of objects that rays can hit
#include "camera.h"          // camera class
#include "material.h"        // materials
#include <fstream>           // writing to files

// computes color of ray as it interacts with objects in scene
vec3 color(const ray& r, hitable *world, int depth) {
    hit_record rec;
    // check if ray hits object in the world
    if(world->hit(r, 0.001, MAXFLOAT, rec)) {
        ray scattered;
        vec3 attenuation;
        // if depth less than 50 & ray scatters when hitting an object, compute attenuation and new scattered ray
        if(depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth + 1);
        } else {
            // return black color otherwise
            return vec3(0, 0, 0);
        }
    } else {
        // if ray doesn't hit any object, find background color
        vec3 unit_dir = unit_vector(r.direction());
        float t = 0.5 * (unit_dir.y() + 1.0);
        // linear interpolation of two colors based on y-component of the unit direction of the ray
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    int width = 800;
    int height = 400;
    int ns = 100;             // number of samples per pixel
    std::ofstream rendering_bucket;
    rendering_bucket.open("render.ppm");   // open an output file stream to write the rendered image

    rendering_bucket << "P3\n" << width << " " << height << "\n255\n";   // PPM image header

    // create list of spheres with positions, radii, & mats
    hitable *list[4];
    list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
    list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
    list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 0.2));
    list[3] = new sphere(vec3(-1, 0, -1), 0.5, new metal(vec3(0.8, 0.8, 0.8), 0.7));
    hitable *world = new hitable_list(list, 4);    // create the world with the list of spheres
    camera cam;  // instantiate a camera

    // iterate over each pixel in image
    for(int y = height - 1; y >= 0; y--) {
        for(int x = 0; x < width; x++) {
            vec3 col(0, 0, 0);
            // for each pixel, shoot `ns` rays for antialiasing
            for(int s = 0; s < ns; s++) {
                float u = float(x + drand48()) / float(width);
                float v = float(y + drand48()) / float(height);
                ray r = cam.get_ray(u, v);
                col += color(r, world, 0);   // accumulate color from all samples
            }
            col /= float(ns);                // average out the colors
            col = vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));   // gamma correction
            // convert color values from [0,1] to [0,255] and write to the PPM file
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            rendering_bucket << ir << " " << ig << " " << ib << "\n";
        }
    }
}
