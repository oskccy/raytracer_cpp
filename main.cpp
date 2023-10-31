#include <iostream>
#include <fstream>

int main() {
	int width = 800;
	int height = 400;

    std::ofstream rendering_bucket;
    rendering_bucket.open("render.ppm");

	rendering_bucket << "P3\n" << width << " " << height << "\n255\n";

	for(int y=height-1; y>=00; y--) {
		for(int x=0; x<width; x++) {
			float r = float(x) / float(width);
			float g = float(y) / float(height);
			float b = 0.2;
			int ir = int(255.99*r);
			int ig = int(255.99*g);
			int ib = int(255.99*b);
			rendering_bucket << ir << " " << ig << " " << ib << "\n";
		}
	}
}