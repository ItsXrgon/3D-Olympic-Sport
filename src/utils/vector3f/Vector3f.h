#ifndef VECTOR3F_H
#define VECTOR3F_H

class Vector3f {
public:
    float x, y, z;

    Vector3f();
    Vector3f(float xx, float yy, float zz);

    // Methods
    Vector3f& Set(float xx, float yy, float zz);
    Vector3f& Normalize();
    Vector3f& CrossProduct(const Vector3f& v);

    // Operators
    Vector3f& operator=(const Vector3f& v);
    Vector3f& operator+=(const Vector3f& v);
    Vector3f& operator-=(const Vector3f& v);
    Vector3f& operator*=(float s);
    Vector3f& operator/=(float s);
    float& operator[](int i);
    operator float* ();

    // Friend functions for additional operations
    friend Vector3f Normalize(const Vector3f& v);
    friend float Length(const Vector3f& v);
    friend Vector3f CrossProduct(const Vector3f& v1, const Vector3f& v2);
    friend float DotProduct(const Vector3f& v1, const Vector3f& v2);
    friend Vector3f operator+(const Vector3f& v1, const Vector3f& v2);
    friend Vector3f operator-(const Vector3f& v1, const Vector3f& v2);
    friend Vector3f operator*(const Vector3f& v, float s);
    friend Vector3f operator*(float s, const Vector3f& v);
    friend Vector3f operator/(const Vector3f& v, float s);
};

#endif
