#ifndef TINYMATH_H
#define TINYMATH_H

#include <cmath>
#include <assert.h>

using namespace std;
struct Vector3D; /**< Forward reference of Vector3D struct */

/**
 * @brief  Vector3D performs vector operations with 3-dimensions
 *
 * The purpose of this struct is primarily for 3D graphics
 * applications.
 */
struct Vector3D{
    /**
     * @brief  Note: x,y,z are a convention
     *
     * x,y,z could be position, but also any 3-component value.
     */
    float x,y,z;

    /**
     * @brief Default conostrutcor
     */
    Vector3D() = default;

    /**
     * @brief  The "Real" constructor we want to use.
     *
     * This initializes the values x,y,z
     */
    Vector3D(float a, float b, float c): x(a), y(b), z(c){}

    /**
     * @brief Override index operator
     *
     * Allowing us to access the individual x,y,z components of our vector
     */
    float& operator[](int i){
        assert(i<3 && i>=0);
        switch (i)
        {
            case 0:
                return this->x;
            case 1:
                return this->y;
            default:
                return this->z;
        }
    }

    /**
     * @brief Override index operator for const argument
     *
     * Allowing us to access the individual x,y,z components of our vector
     */
    const float& operator[](int i) const{
        assert(i<3 && i>=0);
        switch (i)
        {
            case 0:
                return this->x;
            case 1:
                return this->y;
            default:
                return this->z;
        }
    }

    /**
     * @brief Override multiplication operator
     */
    Vector3D& operator *=(float s){
        this->x = this->x * s;
        this->y = this->y * s;
        this->z = this->z * s;
        return *this;
    }

    /**
     * @brief Override division operator
     */
    Vector3D& operator /=(float s){
        this->x = this->x / s;
        this->y = this->y / s;
        this->z = this->z / s;
        return (*this);
    }

    /**
     * @brief Override addition operator
     */
    Vector3D& operator +=(const Vector3D& v){
        this->x = this->x + v.x;
        this->y = this->y + v.y;
        this->z = this->z + v.z;
        return (*this);
    }

    /**
     * @brief Subtraction operator
     */
    Vector3D& operator -=(const Vector3D& v){
        this->x = this->x - v.x;
        this->y = this->y - v.y;
        this->z = this->z - v.z;
        return (*this);
    }

};

/**
 * @brief  Compute the dot product of a Vector3D
 */
inline float Dot(const Vector3D& a, const Vector3D& b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

/**
 * @brief  Multiply a vector by a scalar value
 */
inline Vector3D operator *(const Vector3D& v, float s){
    Vector3D vec = Vector3D (v.x*s, v.y*s, v.z*s);
    return vec;
}

/**
 * @brief Mutiply a scalar value by a vector
 */
inline Vector3D operator *(float s, const Vector3D& v){
    Vector3D vec = Vector3D (v.x*s, v.y*s, v.z*s);
    return vec;
}

/**
 * @brief  Divide a vector by a scalar value
 */
inline Vector3D operator /(const Vector3D& v, float s){
    Vector3D vec = Vector3D (v.x/s, v.y/s, v.z/s);
    return vec;
}

/**
 * @brief Negate the sign of a vector
 */
inline Vector3D operator -(const Vector3D& v){
    Vector3D vec = Vector3D ((-1)*v.x, (-1)*v.y, (-1)*v.z);
    return vec;
}

/**
 * @brief Override equal operator for comparison between vectors
 */
inline bool operator == (const Vector3D& a, const Vector3D& b){
    return (a.x==b.x && a.y==b.y && a.z==b.z);
}

/**
 * @brief Compute the magnitude of a vector
 */
inline float Magnitude(const Vector3D& v){
    return sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));
}

/**
 * @brief Add one vector to another
 */
inline Vector3D operator +(const Vector3D& a, const Vector3D& b){
    Vector3D vec = Vector3D (a.x + b.x, a.y + b.y, a.z + b.z);
    return vec;
}

/**
 * @brief Subtract one vector from another
 */
inline Vector3D operator -(const Vector3D& a, const Vector3D& b){
    Vector3D vec = Vector3D (a.x - b.x, a.y - b.y, a.z - b.z);
    return vec;
}

/**
 * @brief Compute the vector projection of two vectors
 *
 * @returns the vector projection of vector a onto vector b
 */
inline Vector3D Project(const Vector3D& a, const Vector3D& b){
    float cos = Dot(a,b) / (Magnitude(a) * Magnitude(b));
    Vector3D vec = (b/Magnitude(b)) * (Magnitude(a) * cos);
    return vec;
}

/**
 * @brief Normalize a vector
 */
inline Vector3D Normalize(const Vector3D& v){
    Vector3D vec = Vector3D (v.x/Magnitude(v), v.y/Magnitude(v), v.z/Magnitude(v));
    return vec;
}

/**
 * @brief Compute the cross product of two vectors
 */
inline Vector3D CrossProduct(const Vector3D& a, const Vector3D& b){
    Vector3D vec = Vector3D (a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
    return vec;
}

#endif
