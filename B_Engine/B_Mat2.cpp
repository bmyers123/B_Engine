#include "Engine.h"


using namespace b_math;
using namespace b_matrices;

//Constructors

B_Mat2::B_Mat2(void)
{
	m00 = m11 = 1;
	m01 = m10 = 0;
}

B_Mat2::B_Mat2(float M00, float M01, float M10, float M11)
{
	m00 = M00;
	m01 = M01;
	m10 = M10;
	m11 = M11;
}

B_Mat2::B_Mat2(B_Mat2 &m2)
{
	m00 = m2.m00;
	m01 = m2.m01;
	m10 = m2.m10;
	m11 = m2.m11;
}

B_Mat2::B_Mat2(float mat2)
{
	m00 = m01 = m10 = m11 = mat2;
}

//Deconstructor

B_Mat2::~B_Mat2(void){}

//Set Mat2x2 to Identity

void B_Mat2::setMat2toIdentity()
{
	m00 = m11 = 1;
	m01 = m10 = 0;
}

//Mat2x2 Determinant

float B_Mat2::DeterminantMat2(B_Mat2 &m2)
{
	return (m2.m00 * m2.m11) - (m2.m01 * m2.m10);
}

//Mat2x2 Inverse Determinant

float B_Mat2::invDeterminantMat2(B_Mat2 &m2)
{
	return 1.0f/(DeterminantMat2(m2));
}

//Mat2x2 Transpose

B_Mat2 B_Mat2::TransposeMat2(B_Mat2 &m2)
{
	B_Mat2 tempMat2;

	tempMat2.m00 = m2.m00;
	tempMat2.m01 = m2.m10;
	tempMat2.m10 = m2.m01;
	tempMat2.m11 = m2.m11;

	return tempMat2;
}

//Inverse Mat2x2

B_Mat2 B_Mat2::InverseMat2(B_Mat2 &m2)
{
	B_Mat2 tempMat2;

	float ogMat2Det = DeterminantMat2(m2);

	tempMat2.m00 =   m2.m11 / ogMat2Det;
	tempMat2.m01 = - m2.m01 / ogMat2Det;
	tempMat2.m10 = - m2.m10 / ogMat2Det;
	tempMat2.m11 =   m2.m00 / ogMat2Det;

	return tempMat2;
}



