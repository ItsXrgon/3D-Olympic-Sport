#include "Vector3f.h"
#include <cmath>

// Create a vector with zeroed dimensions
Vector3f::Vector3f() : x(0.0f), y(0.0f), z(0.0f) {}

// Create a vector with initialized dimensions
Vector3f::Vector3f(float xx, float yy, float zz) :
	x(xx), y(yy), z(zz) {
}

// Sets the vector
Vector3f& Vector3f::Set(float xx, float yy, float zz) {
	x = xx; y = yy; z = zz;
	return(*this);
}

// Normalizes the vector
Vector3f& Vector3f::Normalize() {
	return(*this /= Length(*this));
}

// Compute the crossproduct
Vector3f& Vector3f::CrossProduct(const Vector3f& v) {
	return(Set(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

// Assignment operator
Vector3f& Vector3f::operator=(const Vector3f& v) {
	return(Set(v.x, v.y, v.z));
}

// Perform addition
Vector3f& Vector3f::operator+=(const Vector3f& v) {
	x += v.x; y += v.y; z += v.z;
	return(*this);
}

// Perform subtraction
Vector3f& Vector3f::operator-=(const Vector3f& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return(*this);
}

// Perform multiplication
Vector3f& Vector3f::operator*=(float s) {
	x *= s; y *= s; z *= s;
	return(*this);
}

// Perform division
Vector3f& Vector3f::operator/=(float s) {
	return(*this *= (1.0f / s));
}

// Perform array lookup
float& Vector3f::operator[](int i) {
	return(*(&x + i));
}

// Convert to a float array
Vector3f::operator float* () {
	return(&x);
}

// Normalize the vector
Vector3f Normalize(const Vector3f& v) {
	return(Vector3f(v) /= Length(v));
}

// Get the length of the vector
float Length(const Vector3f& v) {
	return(float(sqrt(DotProduct(v, v))));
}

// Compute the cross product of two vectors
Vector3f CrossProduct(const Vector3f& v1, const Vector3f& v2) {
	return(Vector3f(v1).CrossProduct(v2));
}

// Compute the dot product of two vectors
float DotProduct(const Vector3f& v1, const Vector3f& v2) {
	return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// Compute the addition of two vectors
Vector3f operator+(const Vector3f& v1, const Vector3f& v2) {
	return(Vector3f(v1) += v2);
}

// Compute the subtraction of two vectors
Vector3f operator-(const Vector3f& v1, const Vector3f& v2) {
	return(Vector3f(v1) -= v2);
}

// Perform multiplication of a vector and scalar float
Vector3f operator*(const Vector3f& v, float s) {
	return(Vector3f(v) *= s);
}

// Perform multiplication of a vector and scalar float
Vector3f operator*(float s, const Vector3f& v) {
	return(Vector3f(v) *= s);
}

// Perform division of a vector and scalar float
Vector3f operator/(const Vector3f& v, float s) {
	return(Vector3f(v) /= s);
}