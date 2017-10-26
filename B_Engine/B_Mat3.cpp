#include "Engine.h"

using namespace b_math;
using namespace b_matrices;
//Constructors Mat3x3

B_Mat3::B_Mat3(void)
{
	m[0] = m[4] = m[8] = 1;
	m[1] = m[2] = m[3] = m[5] = m[6] = m[7] = 0;
}

B_Mat3::B_Mat3(float mat3)
{
	m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] = m[7] = m[8] = mat3;
}

B_Mat3::B_Mat3(float M00, float M01, float M02, float M10, float M11, float M12, float M20, float M21, float M22)
{
	m[0] = M00;
	m[1] = M01;
	m[2] = M02;
	m[3] = M10;
	m[4] = M11;
	m[5] = M12;
	m[6] = M20;
	m[7] = M21;
	m[8] = M22;
}

B_Mat3::B_Mat3(b_math::b_vectors::B_Vec3 &v_row1, b_math::b_vectors::B_Vec3 &v_row2, b_math::b_vectors::B_Vec3 &v_row3)
{
	m[0] = v_row1.x;
	m[1] = v_row1.y;
	m[2] = v_row1.z;

	m[3] = v_row2.x;
	m[4] = v_row2.y;
	m[5] = v_row2.z;

	m[6] = v_row3.x;
	m[7] = v_row3.y;
	m[8] = v_row3.z;
}

B_Mat3::B_Mat3(B_Mat3 &m3)
{
	m[0] = m3.m[0]; m[1] = m3.m[1]; m[2] = m3.m[2];
	m[3] = m3.m[3]; m[4] = m3.m[4]; m[5] = m3.m[5];
	m[6] = m3.m[6]; m[7] = m3.m[7]; m[8] = m3.m[8];
}

//Deconstructors Mat3x3

B_Mat3::~B_Mat3(void){}

//Set Matrix to Identity

void B_Mat3::setMat3ToIdentity()
{
	m[0] = m[4] = m[8] = 1;
	m[1] = m[2] = m[3] = m[5] = m[6] = m[7] = 0;
}

//Mat3x3 Transpose

B_Mat3 B_Mat3::TransposeMat3()
{
	B_Mat3 tempMat3;

	tempMat3.m[0] = m[0];
	tempMat3.m[1] = m[3];
	tempMat3.m[2] = m[6];
	tempMat3.m[3] = m[1];
	tempMat3.m[4] = m[4];
	tempMat3.m[5] = m[7];
	tempMat3.m[6] = m[2];
	tempMat3.m[7] = m[5];
	tempMat3.m[8] = m[8];

	return tempMat3;
}

//Mat3x3 Determinant

float B_Mat3::DeterminantMat3(B_Mat3 &m3)
{
	return (m3.m[0] * ((m3.m[4]*m3.m[8]) - (m3.m[5]*m3.m[7]))) + 
		   (m3.m[1] * ((m3.m[5]*m3.m[6]) - (m3.m[3]*m3.m[8]))) + 
		   (m3.m[2] * ((m3.m[3]*m3.m[7]) - (m3.m[4]*m3.m[6]))) ;
}

//Mat3x3 Inverse Determinant

float B_Mat3::invDeterminantMat3(B_Mat3 &m3)
{
	return 1.0f/(DeterminantMat3(m3));
}

//Mat3x3 Inverse 

B_Mat3 B_Mat3::InverseMat3(B_Mat3 &m3)
{
	B_Mat3 tempMat3;
	float tempDet1, tempDet2, tempDet3, tempDet4, tempDet5, tempDet6, tempDet7, tempDet8, tempDet9;
	float ogMat3InvDet = invDeterminantMat3(m3);
	
	//00 (+)
	B_Mat2 tempMat00(m3.m[4], m3.m[5], m3.m[7], m3.m[8]);
	tempDet1 = tempMat00.DeterminantMat2(tempMat00);
	tempMat3.m[0] = tempDet1 * ogMat3InvDet;

	//01 (-)
	B_Mat2 tempMat01(m3.m[3], m3.m[5], m3.m[6], m3.m[8]);
	tempDet2 = tempMat01.DeterminantMat2(tempMat01);
	tempMat3.m[1] = -tempDet2 * ogMat3InvDet;

	//02 (+)
	B_Mat2 tempMat02(m3.m[3], m3.m[4], m3.m[6], m3.m[7]);
	tempDet3 = tempMat02.DeterminantMat2(tempMat02);
	tempMat3.m[2] = tempDet3 * ogMat3InvDet;

	//10 (-)
	B_Mat2 tempMat10(m3.m[4], m3.m[5], m3.m[7], m3.m[8]);
	tempDet4 = tempMat10.DeterminantMat2(tempMat10);
	tempMat3.m[3] = - tempDet4 * ogMat3InvDet;

	//11 (+)
	B_Mat2 tempMat11(m3.m[0], m3.m[2], m3.m[6], m3.m[8]);
	tempDet5 = tempMat11.DeterminantMat2(tempMat11);
	tempMat3.m[4] = tempDet5 * ogMat3InvDet;

	//12 (-)
	B_Mat2 tempMat12(m3.m[0], m3.m[1], m3.m[6], m3.m[7]);
	tempDet6 = tempMat12.DeterminantMat2(tempMat12);
	tempMat3.m[5] = -tempDet6 * ogMat3InvDet;

	//20 (+)
	B_Mat2 tempMat20(m3.m[1], m3.m[2], m3.m[4], m3.m[5]);
	tempDet7 = tempMat20.DeterminantMat2(tempMat20);
	tempMat3.m[6] = tempDet7 * ogMat3InvDet;

	//21 (-)
	B_Mat2 tempMat21(m3.m[0], m3.m[2], m3.m[3], m3.m[5]);
	tempDet8 = tempMat21.DeterminantMat2(tempMat21);
	tempMat3.m[7] = -tempDet8 * ogMat3InvDet;

	//22 (+)
	B_Mat2 tempMat22(m3.m[0], m3.m[1], m3.m[3], m3.m[4]);
	tempDet9 = tempMat22.DeterminantMat2(tempMat22);
	tempMat3.m[3] = tempDet9 * ogMat3InvDet;

	tempMat3 = tempMat3.TransposeMat3();

	return tempMat3;
}


//FIX THIS FUNCTIONNNNNNNNN!!!!!!!!!!!!!!!!!!!!!!!!! 
//
//The problem lies withing to the multiplication of TransposeMat3(mat3) and 1.0f / tempVec.Dot()



B_Mat3 B_Mat3::B_Mat3InverseUniformScale(B_Mat3 &mat3)
{
	b_math::b_vectors::B_Vec3 tempVec = b_math::b_vectors::B_Vec3(mat3.m[0], mat3.m[1], mat3.m[2]);
	float tempDot = tempVec.Dot(b_math::b_vectors::B_Vec3(mat3.m[0], mat3.m[1], mat3.m[2])  );
	float tempF = 1.0f / tempDot;

	mat3 = mat3.TransposeMat3();
	mat3 = mat3 * tempF;

	return mat3;
}

//----------------------------------------
//Mat 3x3 Rotations

//3x3 Rotate X
B_Mat3 B_Mat3::B_Mat3RotateX(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return B_Mat3( 1,  0,  0, 
				   0,  c,  s, 
				   0, -s,  c );
}  

//3x3 Rotate Y
B_Mat3 B_Mat3::B_Mat3RotateY(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return B_Mat3( c,  0, -s, 
				   0,  1,  0, 
				   s,  0,  c );
}

//3x3 Rotate Z
B_Mat3 B_Mat3::B_Mat3RotateZ(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return B_Mat3( c,  s,  0, 
				  -s,  c,  0, 
				   0,  0,  1 );
}

//Euler Rotations Sequentially (x, y, and z)
B_Mat3 B_Mat3::B_Mat3RotateEulerXYZ(float xangle, float yangle, float zangle)
{
	return B_Mat3( B_Mat3RotateZ(zangle) * B_Mat3RotateY(yangle) * B_Mat3RotateX(xangle) );
}

//Mat3 Operators
//Multiplication w/ another Mat3
B_Mat3 B_Mat3::operator*(B_Mat3 &mat3)
{
	return B_Mat3( (m[0]*mat3.m[0] + m[1]*mat3.m[3] + m[2]*mat3.m[6]), (m[0]*mat3.m[1] + m[1]*mat3.m[4] + m[2]*mat3.m[7]), (m[0]*mat3.m[2] + m[1]*mat3.m[5] + m[2]*mat3.m[8]),
				   (m[3]*mat3.m[0] + m[4]*mat3.m[3] + m[5]*mat3.m[6]), (m[3]*mat3.m[1] + m[4]*mat3.m[4] + m[5]*mat3.m[7]), (m[3]*mat3.m[2] + m[4]*mat3.m[5] + m[5]*mat3.m[8]),
				   (m[6]*mat3.m[0] + m[7]*mat3.m[3] + m[8]*mat3.m[6]), (m[6]*mat3.m[1] + m[7]*mat3.m[4] + m[8]*mat3.m[7]), (m[6]*mat3.m[2] + m[7]*mat3.m[5] + m[8]*mat3.m[8]) );
}

//Multiplication with a Mat3 and Vec3
float B_Mat3::operator*(b_math::b_vectors::B_Vec3 &v3)
{
	return (v3.x*m[0] + v3.y*m[3] + v3.z*m[6]) + (v3.x*m[1] + v3.y*m[4] + v3.z*m[7]) + (v3.x*m[2] + v3.y*m[5] + v3.z*m[8]);
}

B_Mat3 B_Mat3::operator*(float f)
{
	m[0] = m[0]*f;
	m[1] = m[1]*f;
	m[2] = m[2]*f;
	m[3] = m[3]*f;
	m[4] = m[4]*f;
	m[5] = m[5]*f;
	m[6] = m[6]*f;
	m[7] = m[7]*f;
	m[8] = m[8]*f;

	return B_Mat3(m[0], m[1], m[2],
				  m[3], m[4], m[5],
				  m[6], m[7], m[8]);
}