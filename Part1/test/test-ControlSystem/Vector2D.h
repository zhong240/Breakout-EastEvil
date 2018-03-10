#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <assert.h>

using namespace std;
// Forward references of each of the structs
// struct Vector2D;

// Vector3D performs vector operations with 3-dimensions
// The purpose of this class is primarily for 3D graphics
// applications.
struct Vector2D{
    // Note: x,y,z are a convention
    // x,y,z could be position, but also any 3-component value.
    float x,y;
    
    // Default conostrutcor
    Vector2D();
    
    // The "Real" constructor we want to use.
    // This initializes the values x,y,z
    Vector2D(float a, float b);
    
    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    float& operator[](int i);
    
    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    const float& operator[](int i) const;
    
    // Multiplication Operator
    Vector2D& operator *=(float s);
    
    // Division Operator
    Vector2D& operator /=(float s);
    
    // Addition operator
    Vector2D& operator +=(const Vector2D& v);
    
    // Subtraction operator
    Vector2D& operator -=(const Vector2D& v);
    
};

// Compute the dot product of a Vector2D
inline float Dot(const Vector2D& a, const Vector2D& b){
    // TODO:
    return a.x*b.x + a.y*b.y;
}

// Multiplication of a vector by a scalar values
inline Vector2D operator *(const Vector2D& v, float s){
    // TODO:
    Vector2D vec = Vector2D (v.x*s, v.y*s);
    return vec;
}

inline Vector2D operator *(float s, const Vector2D& v){
    // TODO:
    Vector2D vec = Vector2D (v.x*s, v.y*s);
    return vec;
}

// Division of a vector by a scalar value.
inline Vector2D operator /(const Vector2D& v, float s){
    // TODO:
    Vector2D vec = Vector2D (v.x/s, v.y/s);
    return vec;
}

inline Vector2D operator -(const Vector2D& v){
    // TODO:
    Vector2D vec = Vector2D ((-1)*v.x, (-1)*v.y);
    return vec;
}

inline bool operator == (const Vector2D& a, const Vector2D& b){
    return (a.x==b.x && a.y==b.y);
}

inline float Magnitude(const Vector2D& v){
    // TODO:
    return sqrt(pow(v.x,2)+pow(v.y,2));
}

inline Vector2D operator +(const Vector2D& a, const Vector2D& b){
    // TODO:
    Vector2D vec = Vector2D (a.x + b.x, a.y + b.y);
    return vec;
}

inline Vector2D operator -(const Vector2D& a, const Vector2D& b){
    // TODO:
    Vector2D vec = Vector2D (a.x - b.x, a.y - b.y);
    return vec;
}

// Vector Projection
inline Vector2D Project(const Vector2D& a, const Vector2D& b){
    // TODO:
    float cos = Dot(a,b) / (Magnitude(a) * Magnitude(b));
    Vector2D vec = (b/Magnitude(b)) * (Magnitude(a) * cos);
    return vec;
}

inline Vector2D Normalize(const Vector2D& v){
    // TODO:
    Vector2D vec = Vector2D (v.x/Magnitude(v), v.y/Magnitude(v));
    return vec;
}

#endif
