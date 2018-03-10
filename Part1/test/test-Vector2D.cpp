#include "../includes/Vector2D.h"
#include <iostream>

// Add your unit tests somewhere in this file
using namespace std;

/*
 string printVector(const Vector3D& v){
 return "["+to_string(v.x)+", "+to_string(v.y)+", "+to_string(v.z)+"]";
 }
 */

int main(int argc, char* args[]){
    
    // Add your unit tests somewhere in this file
    Vector2D vec1 = Vector2D (3.0f, 4.0f);
    Vector2D vec2 = Vector2D (7.5f, 8.5f);
    
    // Test1:
    float vec1X = vec1[0];
    assert (vec1X == 3.0f);
    if (vec1X==3.0f)
    {
        cout<<"pass operator []"<<endl;
    }
    
    
    vec1 *= 3;
    assert (vec1 == Vector2D (9.0f, 12.0f));
    if (vec1 == Vector2D (9.0f, 12.0f))
    {
        cout<<"pass *="<<endl;
    }
    
    vec1 /= 3;
    assert (vec1 == Vector2D (3.0f, 4.0f));
    if (vec1 == Vector2D (3.0f, 4.0f))
    {
        cout<<"pass /="<<endl;
    }
    
    vec1 += Vector2D (4.5f, 4.5f);
    assert (vec1 == vec2);
    if (vec1 == vec2)
    {
        cout<<"pass +="<<endl;
    }
    
    vec1 -= Vector2D (4.5f, 4.5f);
    assert (vec1 == Vector2D(3.0f, 4.0f));
    if (vec1 == Vector2D (3.0f, 4.0f))
    {
        cout<<"pass -="<<endl;
    }
    
//    // Test 2;
//    assert(Dot(vec1, vec2)==104);
//    if (Dot(vec1, vec2) == 104)
//    {
//        cout<<"pass Dot()"<<endl;
//    }
//
//    assert(vec1 == Vector3D (6.0f, 8.0f, 10.0f)/2);
//    if (Vector3D (6.0f, 8.0f, 10.0f)/2 == vec1)
//    {
//        cout<<"pass /"<<endl;
//    }
//
//    assert (2*vec1 == Vector3D (6.0f, 8.0f, 10.0f));
//    if (Vector3D (6.0f, 8.0f, 10.0f) == vec1*2)
//    {
//        cout<<"pass *"<<endl;
//    }
//
//    assert (Vector3D (-3.0f, -4.0f, -5.0f) == -vec1);
//    if (Vector3D (-3.0f, -4.0f, -5.0f) == -vec1)
//    {
//        cout<<"pass - (negative)"<<endl;
//    }
//
//    assert (Magnitude( vec1 ) == 7.071068f);
//    if (Magnitude( vec1 ) == 7.071068)
//    {
//        cout<<"pass Magnitude()"<<endl;
//    }
//
//    assert ((vec1 + vec2) == Vector3D(10.5f, 12.5f, 14.5f));
//    if ((vec1 + vec2) == Vector3D(10.5f, 12.5f, 14.5f))
//    {
//        cout<<"pass +"<<endl;
//    }
//
//    assert ((vec2 - vec1) == Vector3D(4.5f, 4.5f, 4.5f));
//    if ((vec2 - vec1) == Vector3D(4.5f, 4.5f, 4.5f))
//    {
//        cout<<"pass - (minus)"<<endl;
//    }
//
//    assert (Project(Vector3D(1.0f, 0.0f, 0.0f), Vector3D(0.0f, 1.0f, 0.0f)) == Vector3D(0.0f, 0.0f, 0.0f));
//    if (Project(Vector3D(1.0f, 0.0f, 0.0f), Vector3D(0.0f, 1.0f, 0.0f)) == Vector3D(0.0f, 0.0f, 0.0f))
//    {
//        cout<<"pass Project()"<<endl;
//    }
//
//    assert (Normalize(vec1) == Normalize(vec1*2));
//    if (Normalize(vec1) == Normalize(vec1*2))
//    {
//        cout<<"pass Normalize()"<<endl;
//    }
//
//    assert (CrossProduct(Vector3D(0,1,0), Vector3D(1, 0, 0)) == Vector3D(0, 0, -1));
//    if (CrossProduct(Vector3D(0,1,0), Vector3D(1, 0, 0)) == Vector3D(0, 0, -1))
//    {
//        cout<<"pass CrossPruduct()"<<endl;
//    }
//
//
//    Matrix3D A = Matrix3D(Vector3D(1.0f, 0.0f, 0.0f),
//                          Vector3D(0.0f, 1.0f, 0.0f),
//                          Vector3D(0.0f, 0.0f, 1.0f));
//    Matrix3D B = Matrix3D(Vector3D(0.0f, 0.0f, 1.0f),
//                          Vector3D(0.0f, 1.0f, 0.0f),
//                          Vector3D(1.0f, 0.0f, 0.0f));
//    Matrix3D C = Matrix3D(Vector3D(1.0f, 0.0f, 0.0f),
//                          Vector3D(0.0f, 1.0f, 0.0f),
//                          Vector3D(0.0f, 0.0f, 1.0f));
//
//    assert (B * A == B);
//    if (B * A == B)
//    {
//        cout<<"pass Matirx *"<<endl;
//    }
//
//    assert (A * Vector3D(1, 0, 0) == Vector3D(1, 0, 0));
//    if (A * Vector3D(1, 0, 0) == Vector3D(1, 0, 0))
//    {
//        cout<<"pass Matirx * (vector)"<<endl;
//    }
//
    return 0;
}
