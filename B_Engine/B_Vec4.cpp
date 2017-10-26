#include "Engine.h"

using namespace b_math;
using namespace b_vectors;

B_Vec4::B_Vec4(void)
{
	x = y = z = w = r = g = b = a =	s = t = p = q = 0;
	v[0] = v[1] = v[2] = v[3] = 0;
}

B_Vec4::B_Vec4(float V)
{
	x = y = z = w = V;
	r = g = b = a = V;
	s = t = p = q = V;
	v[0] = v[1] = v[2] = v[3] = V;
}

B_Vec4::B_Vec4(B_Vec3 vec3, float W)
{
	x = r = s = v[0] = vec3.x;
	y = g = t = v[1] = vec3.y;
	z = b = p = v[2] = vec3.z;
	w = a = q = v[3] = W;
}

B_Vec4::B_Vec4(float X, float Y, float Z, float W)
{
	x = r = s = v[0] = X;
	y = g = t = v[1] = Y;
	z = b = p = v[2] = Z;
	w = a = q = v[3] = W;
}

B_Vec4::B_Vec4(const float *Vp)
{
	x =*(Vp); y =*(Vp+1); z =*(Vp+2); w =*(Vp+3);
}

const float B_Vec4::operator[](unsigned char r) const
{
	return *(v+r);
}

float &B_Vec4::operator[](unsigned char r)
{
	return *(v+r);
}

//B_Vec4 Operators
//
//Returning Vec4's
B_Vec4 B_Vec4::operator+(const B_Vec4 &v4)
{
	return B_Vec4(x+v4.x, y+v4.y, z+v4.z, w+v4.w);
}

B_Vec4 B_Vec4::operator-(const B_Vec4 &v4)
{
	return B_Vec4(x-v4.x, y-v4.y, z-v4.z, w-v4.w);
}

B_Vec4 B_Vec4::operator/(const B_Vec4 &v4)
{
	return B_Vec4(x/v4.x, y/v4.y, z/v4.z, w/v4.w);
}

B_Vec4 B_Vec4::operator*(const B_Vec4 &v4)
{
	return B_Vec4(x*v4.x, y*v4.y, z*v4.z, w*v4.w);
}
//
//Adding to current
//
void B_Vec4::operator+=(const B_Vec4 &v4)
{
	x = x + v4.x;
	y = y + v4.y;
	z = z + v4.z;
	w = w + v4.w;
}

void B_Vec4::operator-=(const B_Vec4 &v4)
{
	x = x - v4.x;
	y = y - v4.y;
	z = z - v4.z;
	w = w - v4.w;
}

void B_Vec4::operator/=(const B_Vec4 &v4)
{
	x = x/v4.x;
	y = y/v4.y;
	z = z/v4.z;
	w = w/v4.w;
}

void B_Vec4::operator*=(const B_Vec4 &v4)
{
	x = x*v4.x;
	y = y*v4.y;
	z = z*v4.z;
	w = w*v4.w;
}

B_Vec4::~B_Vec4(void){}

//Dot Product
float B_Vec4::dotProductV4(const B_Vec4 &v0, const B_Vec4 &v1)
{
	return ( v0.x*v1.x + v0.y*v1.y + v0.z*v1.z + v0.w*v1.w );
}

