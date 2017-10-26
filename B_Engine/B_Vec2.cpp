#include "Engine.h"

using namespace b_math;
using namespace b_vectors;

B_Vec2::B_Vec2()
{
	x = 0.0f; 
	y = 0.0f;
}

B_Vec2::B_Vec2(float X, float Y)
{
	x = X;
	y = Y;
}

B_Vec2::B_Vec2(const float *Vp)
{
	x =*(Vp);	y =*(Vp+1);
}

B_Vec2::B_Vec2(const B_Vec2 &vec2)
{
	x = vec2.x;
	y = vec2.y;
}

B_Vec2::~B_Vec2(void){}

//Vec2 Negations
void B_Vec2::NegateVec2XY()
{
	x = -x;
	y = -y;
}

void B_Vec2::NegateVec2X()
{
	x = -x;
}

void B_Vec2::NegateVec2Y()
{
	y = -y;
}

//Length of Vec2
float B_Vec2::GetLenghtVec2()
{
	return (float)sqrt(x*x + y*y);
}

//Operators

//
const float B_Vec2::operator[](unsigned char r)const
{
	return *(v + r);
}

//
float &B_Vec2::operator[](unsigned char r)
{
	return *(v + r);
}

//Plus
B_Vec2 B_Vec2::operator+(const B_Vec2 &v2)
{
	return B_Vec2(x + v2.x, y + v2.y);
}

//Minus
B_Vec2 B_Vec2::operator-(const B_Vec2 &v2)
{
	return B_Vec2( x+v2.x, y+v2.y );
}

//Divided By
B_Vec2 B_Vec2::operator/(const B_Vec2 &v2)
{
	return B_Vec2( x/v2.x, y/v2.y );
}

B_Vec2 B_Vec2::operator/(float f)
{
	return B_Vec2( x/f, y/f );
}

//Mutiplied By
B_Vec2 B_Vec2::operator*(const B_Vec2 &v2)
{
	return B_Vec2( x*v2.x, y*v2.y );
}

B_Vec2 B_Vec2::operator*(float f)
{
	return B_Vec2( x*f, y*f );
}

//Multiply and Equal
void B_Vec2::operator*=(const B_Vec2 &v2)
{
	x *= v2.x;
	y *= v2.y;
}

//Plus Equal
void B_Vec2::operator+=(const B_Vec2 &v2)
{
	x = x + v2.x;
	y = y + v2.y;
}

void B_Vec2::operator+=(const float &f)
{
	x = x + f;
	y = y + f;
}

//Minus Equal
void B_Vec2::operator-=(const B_Vec2 &v2)
{
	x -= v2.x;
	y -= v2.y;
}

//Divided Equal
void B_Vec2::operator/=(const B_Vec2 &v2)
{
	x /= v2.x;
	y /= v2.y;
}

//Comparison Operators

//Equal to?
bool B_Vec2::operator==(const B_Vec2 &v2)
{
	if(x == v2.x && y == v2.y)return true; else return false;
}

//Set Equal
void B_Vec2::operator=(const B_Vec2 &v2)
{
	x = v2.x;
	y = v2.y;
}

//Vec2 Dot Product
float B_Vec2::DotProductVec2(B_Vec2 &v2)
{
	return (x * v2.x) + (y * v2.y);
}

//Vec2 Cross Product
B_Vec2 B_Vec2::CrossProductVec2(B_Vec2 &v2)
{
	float length = sqrt(x * x + y * y);

   if(length <= 0.00001f) {return B_Vec2(0.0f, 1.0f);}

   length = 1.0f / length;

   return B_Vec2(x*length, y*length);
}

//Vec2 Normalize
B_Vec2 B_Vec2::NormalizeVec2(B_Vec2 &v2)
{
	float vec2Length = v2.GetLenghtVec2();

	B_Vec2 normalVec2(v2.x/vec2Length, v2.y/vec2Length);

	return normalVec2;
}