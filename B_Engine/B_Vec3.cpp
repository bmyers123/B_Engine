#include "Engine.h"

using namespace b_math;
using namespace b_vectors;

float B_Vec3::B_sinAngle = 0.0f;
float B_Vec3::B_cosAngle = 0.0f;
//B_Vec3 B_Vec3::tempV = B_Vec3(0.0f, 0.0f, 0.0f);

B_Vec3::B_Vec3()
{
	v[0] = x = 0.0f;
	v[1] = y = 0.0f;
	v[2] = z = 0.0f;

}

//------------------------------------------------------------------
//Deconstructors

B_Vec3::~B_Vec3(){}

//------------------------------------------------------------------
//Constructors
B_Vec3::B_Vec3(const float *Vp)
{
	x =*(Vp); y =*(Vp+1); z =*(Vp+2);
}

B_Vec3::B_Vec3(float xyz)
{
	v[0] = x = xyz;
	v[1] = y = xyz;
	v[2] = z = xyz;
}

B_Vec3::B_Vec3(float X, float Y, float Z)
{
	v[0] = x = X;
	v[1] = y = Y;
	v[2] = z = Z;
}

B_Vec3::B_Vec3(const B_Vec3 &v3)
{
	v[0] = x = v3.x;
	v[1] = y = v3.y;
	v[2] = z = v3.z;
}

//------------------------------------------------------------------
//Mathematical Operators

//Plus
B_Vec3 B_Vec3::operator+(const B_Vec3 &v3)
{
	return B_Vec3( x+v3.x, y+v3.y, z+v3.z );
}
B_Vec3 B_Vec3::operator+(const float f)
{
	return B_Vec3( x+f, y+f, z+f );
}

//Minus
B_Vec3 B_Vec3::operator-(const B_Vec3 &v3)
{
	return B_Vec3( x-v3.x, y-v3.y, z-v3.z );
}

//B_Vec3 operator-(const B_Vec3 &v3, const B_Vec3 &v32)
//{
//	
//}

//Divided By
B_Vec3 B_Vec3::operator/(const B_Vec3 &v3)
{
	return B_Vec3( x/v3.x, y/v3.y, z/v3.z );
}

B_Vec3 B_Vec3::operator/(float f)
{
	return B_Vec3( x/f, y/f, z/f);
}

//Multiplied By
B_Vec3 B_Vec3::operator*(const B_Vec3 &v3)
{
	return B_Vec3( x*v3.x, y*v3.y, z*v3.z );
}

B_Vec3 B_Vec3::operator*(float f)
{
	return B_Vec3( x*f, y*f, z*f);
}

//B_Vec3 B_Vec3::operator*(B_Mat3 &m3)
//{
//	return B_Vec3( (x*m3.m00 + y*m3.m10 + z*m3.m20), (x*m3.m01 + y*m3.m11 + z*m3.m21), (x*m3.m02 + y*m3.m12 + z*m3.m22) );
//}

//----------
//Plus Equal
void B_Vec3::operator+=(const B_Vec3 &v3)
{
	x += v3.x;
	y += v3.y;
	z += v3.z;
}

//----------
//Minus Equal
void B_Vec3::operator-=(const B_Vec3 &v3)
{
	x -= v3.x;
	y -= v3.y;
	z -= v3.z;
}

//----------
//Times Equal
void B_Vec3::operator*=(const B_Vec3 &v3)
{
	x *= v3.x;
	y *= v3.y;
	z *= v3.z;
}

//----------
//Divide Equal
void B_Vec3::operator/=(const B_Vec3 &v3)
{
	x /= v3.x;
	y /= v3.y;
	z /= v3.z;
}

const float B_Vec3::operator[](unsigned char r) const
{
	return *(v+r);
}

float &B_Vec3::operator[](unsigned char r)
{
	return *(v+r);
}

//------------------------------------------------------------------
//Comparison Operators

//----------
//Check Equal
 bool B_Vec3::operator==(const B_Vec3 &v3)
{
	if(x == v3.x && y == v3.y && z == v3.z)
		return true;
	else 
		return false;
}

//----------
//Set Equal
 void B_Vec3::operator=(const B_Vec3 &v3)
 {
	v[0] = v3.x;
	v[1] = v3.y;
	v[2] = v3.z;
 
	x = v3.x;
	y = v3.y;
	z = v3.z;
 
 }

 void B_Vec3::setEqualTo(B_Vec3 &v3)
 {
	v[0] = x = v3.x;
	v[1] = y = v3.y;
	v[2] = z = v3.z;
 }

//------------------------------------------------------------------
//Mathematical Vector Functions

//----------
//Negate Vector
 void B_Vec3::Negate()
 {
	v[0] = x = -x;
	v[1] = y = -y;
	v[2] = z = -z;
 }

//----------
//Normalize Vector
 B_Vec3 B_Vec3::Normalize()
 {
 
   float length = sqrt(x * x + y * y + z * z);

   if(length <= 0.00001f) {return B_Vec3(0.0f, 1.0f, 0.0f);}

   length = 1.0f / length;

   return B_Vec3(x*length, y*length, z*length);

 }

  B_Vec3 B_Vec3::Normalize(B_Vec3 &v3)
 {
 
   float length = sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);

   if(length <= 0.00001f) {return B_Vec3(0.0f, 1.0f, 0.0f);}

   length = 1.0f / length;

   return B_Vec3(v3.x*length, v3.y*length, v3.z*length);

 }

//----------
//Length of Vector
 float B_Vec3::GetLengthVec3()
 {
	return (float)sqrt(x*x + y*y + z*z);
 }

//----------
//Distance Between Vectors
 float B_Vec3::GetDistanceFrom(B_Vec3 &v3)
 {

	float tempX = 0.0f;
	tempX  = v3.x - x;
	tempX *= tempX;

	float tempY = 0.0f;
	tempY  = v3.y - y;
	tempY *= tempY;

	float tempZ = 0.0f;
	tempZ  = v3.z - z;
	tempZ *= tempZ;

	return sqrt(tempX + tempY + tempZ);

 }

//----------
//Dot Products
 float B_Vec3::Dot(B_Vec3 &v3)
 {
	return v3.x * x + v3.y * y + v3.z * z;
 }

//Returns angle b/w 2 vectors
 float B_Vec3::DotAngle(B_Vec3 &v3_1, B_Vec3 &v3_2)
 {
	float tempLen1 = v3_1.GetLengthVec3();
	float tempLen2 = v3_2.GetLengthVec3();

	float tempDot = v3_1.Dot(v3_2);

	float angle = tempDot / (sqrt(tempLen1) * sqrt(tempLen2));

	angle = acos(angle);

	return angle;
 }

//----------
//Cross Product
 B_Vec3 B_Vec3::Cross(B_Vec3 &v3)
 {
	return B_Vec3( y*v3.z - z*v3.y, 

				   z*v3.x - x*v3.z,

				   x*v3.y - y*v3.x );
 }

 B_Vec3 B_Vec3::Cross(B_Vec3 &v3, B_Vec3 &v32)
 {
	return B_Vec3(v3.y*v32.z-v3.z*v32.y, 
				  v3.z*v32.x-v3.x*v32.z, 
				  v3.x*v32.y-v3.y*v32.x);
 }
 
 B_Vec3 B_Vec3::crossNormalize(B_Vec3 &v3, B_Vec3 &v32)
 {
	return B_Vec3(		Normalize(Cross(v3, v32))		);
 }

//------------------------------------------------------------------
//Rotations
 void B_Vec3::RotateX(float angle)
 {
 	B_sinAngle = sin(DTR*angle);
	B_cosAngle = cos(DTR*angle);
	
	y = y*B_cosAngle - z*B_sinAngle;
	z = y*B_sinAngle + z*B_cosAngle;
 }

 void B_Vec3::RotateY(float angle)
 {
 	B_sinAngle = sin(DTR*angle);
	B_cosAngle = cos(DTR*angle);

	x =  x*B_cosAngle + z*B_sinAngle;
	z = -x*B_sinAngle + z*B_cosAngle;
 }

 void B_Vec3::RotateZ(float angle)
 {
 	B_sinAngle = sin(DTR*angle);
	B_cosAngle = cos(DTR*angle);
	
	x = x*B_cosAngle - y*B_sinAngle;
	y = x*B_sinAngle + y*B_cosAngle;
 }

 void B_Vec3::PolartoVector(float azemuth, float elevation, float distance)
{
	B_sinAngle = azemuth*DTR;
	B_cosAngle = elevation*DTR;

	B_Vec3 tempV;

	tempV.x = sin(B_sinAngle);
	tempV.z = cos(B_sinAngle)*(-1.0f);
	tempV.y = cos(B_cosAngle);

	x = tempV.x * tempV.y * distance;
	z = tempV.z * tempV.y * distance;
	y = sin(B_cosAngle)*(-1.0f) * distance;
}

B_Vec3 B_Vec3::VectortoPolar(B_Vec3 target)
{
	B_Vec3 output;

	output.y = 180.0f-(atan2(target.x, target.z)*RTD);

	if(output.y<0.0f){output.y+=360.0f;}
	
	B_Vec3 tempV;

	tempV = target;
	tempV.y = 0.0f;
	output.x = (atan2(tempV.GetLengthVec3(), target.y)*RTD)-90.0f;

	if(output.x<0.0f){output.x+=360.0f;}

	output.z = (float)sqrt(target.x * target.x + target.y * target.y + target.z * target.z);

	return output;
}