#include <math.h>    // include math lib for math funcs
#include <stdlib.h>  // include std for memory allocation
#include <iostream> 

class vec3 {
public:
    vec3() {}   // default constructor for a vec3 object
    vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; } // parameterized constructor

    // accessor functions to get individual components of the vector
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float r() const { return e[0]; }
    inline float g() const { return e[1]; }
    inline float b() const { return e[2]; }

    inline const vec3& operator+() const { return *this; }  // unary plus operator
    inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } // unary minus operator
    inline float operator[](int i) const { return e[i]; }   // indexing operator (read-only)
    inline float& operator[](int i) { return e[i]; }         // indexing operator (read/write)

    // compound assignment operators
    inline vec3& operator+=(const vec3& v2);
    inline vec3& operator-=(const vec3& v2);
    inline vec3& operator*=(const vec3& v2);
    inline vec3& operator/=(const vec3& v2);
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);

    // compute the length of the vector
    inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }

    // compute the squared length of the vector
    inline float length_squared() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    // normalize the vector (make it a unit vector)
    inline void make_unit_vector();

    float e[3];  // array to store the vector components
};

// overload input stream operator (used for reading vec3 from input)
inline std::istream& operator>>(std::istream& is, vec3& t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

// overload output stream operator (used for writing vec3 to output)
inline std::ostream& operator<<(std::ostream& os, vec3& t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

// normalize the vector in-place
inline void vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}

// binary operators for element-wise vector operations
inline vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline vec3 operator-(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}
inline vec3 operator*(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}
inline vec3 operator/(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

// scalar multiplication and division operators
inline vec3 operator*(float t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}
inline vec3 operator/(float t, const vec3& v) {
    return vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
}
inline vec3 operator/(const vec3& v, float t) {
    return vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

// calculate the dot product of two vectors (see readme)
inline float dot(const vec3& v1, const vec3& v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

// calculate the cross product of two vectors (see readme)
inline vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2[1],
                -(v1.e[0] * v2.e[2] - v1.e[2] * v2[0]),
                v1.e[0] * v2.e[1] - v1.e[1] * v2[0]);
}

// compound assignment operators for element-wise vector operations
inline vec3& vec3::operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}
inline vec3& vec3::operator-=(const vec3& v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}
inline vec3& vec3::operator*=(const vec3& v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}
inline vec3& vec3::operator/=(const vec3& v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}
inline vec3& vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}
inline vec3& vec3::operator/=(const float t) {
    float k = 1.0 / t;
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

// compute the unit vector of a given vector
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}
