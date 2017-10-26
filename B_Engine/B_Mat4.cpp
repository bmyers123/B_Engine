#include "Engine.h"


using namespace b_math;
using namespace b_matrices;

//Constructors Mat4x4
B_Mat4::B_Mat4(void)
{
	//m[0] = m[5] = m[10] = m[15] = 1;
	//m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = m[11] = m[12] = m[13] = m[14] = 0;

	//mat4_4[0][0] = mat4_4[1][1] = mat4_4[2][2] = mat4_4[3][3] = 1;
	//mat4_4[0][1] = mat4_4[0][2] = mat4_4[0][3] = mat4_4[1][0] = mat4_4[1][2] = mat4_4[1][3] = mat4_4[2][0] = mat4_4[2][1] = mat4_4[2][3] = mat4_4[3][0] = mat4_4[3][1] = mat4_4[3][2] = 0;

	m[0] = m[5] = m[10] = m[15] = 1;
	m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = m[11] = m[12] = m[13] = m[14] = 0;


}

B_Mat4::B_Mat4(float m0, float m1, float m2, float m3,  float m4, float m5, float m6, float m7,  float m8, float m9, float m10, float m11,  float m12, float m13, float m14, float m15)
{
	//m[0] = Bm[0]; m[1] = Bm[1]; m[2] = Bm[2]; m[3] = Bm[3];
	//m[4] = Bm[4]; m[5] = Bm[5]; m[6] = Bm[6]; m[7] = Bm[7];
	//m[8] = Bm[8]; m[9] = Bm[9]; m[10] = Bm[10]; m[11] = Bm[11];
	//m[12] = Bm[12]; m[13] = Bm[13]; m[14] = Bm[14]; m[15] = Bm[15];

	m[0] = m0;
	m[1] = m1;
	m[2] = m2;
	m[3] = m3;
	m[4] = m4;
	m[5] = m5;
	m[6] = m6;
	m[7] = m7;
	m[8] = m8;
	m[9] = m9;
	m[10] = m10;
	m[11] = m11;
	m[12] = m12;
	m[13] = m13;
	m[14] = m14;
	m[15] = m15;

	//mat4_4[0][0] = Bm[0]; mat4_4[0][1] = Bm[1]; mat4_4[0][2] = Bm[2]; mat4_4[0][3] = Bm[3];
	//mat4_4[1][0] = Bm[4]; mat4_4[1][1] = Bm[5]; mat4_4[1][2] = Bm[6]; mat4_4[1][3] = Bm[7];
	//mat4_4[2][0] = Bm[8]; mat4_4[2][1] = Bm[9]; mat4_4[2][2] = Bm[10]; mat4_4[2][3] = Bm[11];
	//mat4_4[3][0] = Bm[12]; mat4_4[3][1] = Bm[13]; mat4_4[3][2] = Bm[14]; mat4_4[3][3] = Bm[15];
}

B_Mat4::B_Mat4(B_Mat4 &m4)
{
	//m[0] = m4.m[0]; m[1] = m4.m[1]; m[2] = m4.m[2]; m[3] = m4.m[3];
	//m[4] = m4.m[4]; m[5] = m4.m[5]; m[6] = m4.m[6]; m[7] = m4.m[7];
	//m[8] = m4.m[8]; m[9] = m4.m[9]; m[10] = m4.m[10]; m[11] = m4.m[11];
	//m[12] = m4.m[12]; m[13] = m4.m[13]; m[14] = m4.m[14]; m[15] = m4.m[15];

	m[0] = m4.m[0];
	m[1] = m4.m[1];
	m[2] = m4.m[2];
	m[3] = m4.m[3];
	m[4] = m4.m[4];
	m[5] = m4.m[5];
	m[6] = m4.m[6];
	m[7] = m4.m[7];
	m[8] = m4.m[8];
	m[9] = m4.m[9];
	m[10] = m4.m[10];
	m[11] = m4.m[11];
	m[12] = m4.m[12];
	m[13] = m4.m[13];
	m[14] = m4.m[14];
	m[15] = m4.m[15];

	//mat4_4[0][0] = m4.m[0]; mat4_4[0][1] = m4.m[1]; mat4_4[0][2] = m4.m[2]; mat4_4[0][3] = m4.m[3];
	//mat4_4[1][0] = m4.m[4]; mat4_4[1][1] = m4.m[5]; mat4_4[1][2] = m4.m[6]; mat4_4[1][3] = m4.m[7];
	//mat4_4[2][0] = m4.m[8]; mat4_4[2][1] = m4.m[9]; mat4_4[2][2] = m4.m[10]; mat4_4[2][3] = m4.m[11];
	//mat4_4[3][0] = m4.m[12]; mat4_4[3][1] = m4.m[13]; mat4_4[3][2] = m4.m[14]; mat4_4[3][3] = m4.m[15];
}

B_Mat4::B_Mat4(b_math::b_vectors::B_Vec4 &v1, b_math::b_vectors::B_Vec4 &v2, b_math::b_vectors::B_Vec4 &v3, b_math::b_vectors::B_Vec4 &v4)
{
	//m[0] = v1.x; m[1] = v1.y; m[2] = v1.z; m[3] = v1.w;
	//m[4] = v2.x; m[5] = v2.y; m[6] = v2.z; m[7] = v2.w;
	//m[8] = v3.x; m[9] = v3.y; m[10] = v3.z; m[11] = v3.w;
	//m[12] = v4.x; m[13] = v4.y; m[14] = v4.z; m[15] = v4.w;

	m[0] = v1.x; m[1] = v1.y; m[2] = v1.z; m[3] = v1.w;
	m[4] = v2.x; m[5] = v2.y; m[6] = v2.z; m[7] = v2.w;
	m[8] = v3.x; m[9] = v3.y; m[10] = v3.z; m[11] = v3.w;
	m[12] = v4.x; m[13] = v4.y; m[14] = v4.z; m[15] = v4.w;

	//mat4_4[0][0] = v1.x; mat4_4[0][1] = v1.y; mat4_4[0][2] = v1.z; mat4_4[0][3] = v1.w;
	//mat4_4[1][0] = v2.x; mat4_4[1][1] = v2.y; mat4_4[1][2] = v2.z; mat4_4[1][3] = v2.w;
	//mat4_4[2][0] = v3.x; mat4_4[2][1] = v3.y; mat4_4[2][2] = v3.z; mat4_4[2][3] = v3.w;
	//mat4_4[3][0] = v4.x; mat4_4[3][1] = v4.y; mat4_4[3][2] = v4.z; mat4_4[3][3] = v4.w;
}

B_Mat4::B_Mat4(float mat[16])
{
	//m[0] = mat[0]; m[1] = mat[1]; m[2] = mat[2]; m[3] = mat[3];
	//m[4] = mat[4]; m[5] = mat[5]; m[6] = mat[6]; m[7] = mat[7];
	//m[8] = mat[8]; m[9] = mat[9]; m[10] = mat[10]; m[11] = mat[11];
	//m[12] = mat[12]; m[13] = mat[13]; m[14] = mat[14]; m[15] = mat[15];

	m[0] = mat[0];
	m[1] = mat[1];
	m[2] = mat[2];
	m[3] = mat[3];
	m[4] = mat[4];
	m[5] = mat[5];
	m[6] = mat[6];
	m[7] = mat[7];
	m[8] = mat[8];
	m[9] = mat[9];
	m[10] = mat[10];
	m[11] = mat[11];
	m[12] = mat[12];
	m[13] = mat[13];
	m[14] = mat[14];
	m[15] = mat[15];

	//mat4_4[0][0] = mat[0]; mat4_4[0][1] = mat[1]; mat4_4[0][2] = mat[2]; mat4_4[0][3] = mat[3];
	//mat4_4[1][0] = mat[4]; mat4_4[1][1] = mat[5]; mat4_4[1][2] = mat[6]; mat4_4[1][3] = mat[7];
	//mat4_4[2][0] = mat[8]; mat4_4[2][1] = mat[9]; mat4_4[2][2] = mat[10]; mat4_4[2][3] = mat[11];
	//mat4_4[3][0] = mat[12]; mat4_4[3][1] = mat[13]; mat4_4[3][2] = mat[14]; mat4_4[3][3] = mat[15];
}


//****Add Constructor with 4 Vec4's once Vec4 class is made

//Desconstructor Mat4x4
B_Mat4::~B_Mat4(void){}

//-----------------------------------------------------
//Mat4x4's

//Transpose Mat4x4
B_Mat4 B_Mat4::TransposeMat4(B_Mat4 &m4)
{
	/*

	[ 01 02 03 04 ] Transpose:	[ 01 05 09 13 ]
	[ 05 06 07 08 ]				[ 02 06 10 14 ]
	[ 09 10 11 12 ]				[ 03 07 11 15 ]
	[ 13 14 15 16 ]				[ 04 08 12 16 ]

	*/
	B_Mat4 *tempMat4 = &m4;

	m4.m[0] = tempMat4->m[0];
	m4.m[1] = tempMat4->m[4];
	m4.m[2] = tempMat4->m[8];
	m4.m[3] = tempMat4->m[12];
	m4.m[4] = tempMat4->m[1];
	m4.m[5] = tempMat4->m[5];
	m4.m[6] = tempMat4->m[9];
	m4.m[7] = tempMat4->m[13];
	m4.m[8] = tempMat4->m[2];
	m4.m[9] = tempMat4->m[6];
	m4.m[10] = tempMat4->m[10];
	m4.m[11] = tempMat4->m[14];
	m4.m[12] = tempMat4->m[3];
	m4.m[13] = tempMat4->m[7];
	m4.m[14] = tempMat4->m[11];
	m4.m[15] = tempMat4->m[15];

	delete tempMat4;
	return m4;

}

//Determinant Mat4x4
float B_Mat4::DeterminantMat4(B_Mat4 &m4)
{
	return ((m[0] * m[14]) * (m[9] * m[15] - m[11] * m[13])) +
		   ((m[1] * m[11]) * (m[10] * m[12] - m[8] * m[14])) +
		   ((m[2] * m[8]) * (m[7] * m[13] - m[9] * m[15])) +
		   ((m[3] * m[9]) * (m[4] * m[14] - m[6] * m[12]));
}

//Inverse Determinant Mat4x4
float B_Mat4::invDeterminantMat4(B_Mat4 &m4)
{
	return 1.0f / DeterminantMat4(m4); 
}

//Inverse Mat4x4
B_Mat4 B_Mat4::InverseMat4(B_Mat4 &m4)
{
	B_Mat4 tempMat4;
	float  tempDet1,  tempDet2,  tempDet3,  tempDet4, 
		   tempDet5,  tempDet6,  tempDet7,  tempDet8,
		   tempDet9, tempDet10, tempDet11, tempDet12, 
		  tempDet13, tempDet14, tempDet15, tempDet16;

	float ogMat4InvDet = invDeterminantMat4(m4);
	//Regular positions in tempMat4 are set to the positions predetermined for an inversed matrix (transpose and all)

//--------------------------------------------------------------
//ROW 1
	//00 (+)
	B_Mat3 tempMat00(m4.m[5], m4.m[6], m4.m[7],
					 m4.m[9], m4.m[10], m4.m[11],
					 m4.m[13], m4.m[14], m4.m[15]);
	tempDet1 = tempMat00.DeterminantMat3(tempMat00);
	tempMat4.m[0] = tempDet1 * ogMat4InvDet;

	//01 (-)
	B_Mat3 tempMat01(m4.m[4], m4.m[6], m4.m[7],
					 m4.m[8], m4.m[10], m4.m[11],
					 m4.m[12], m4.m[14], m4.m[15]);
	tempDet2 = tempMat01.DeterminantMat3(tempMat01);
	tempMat4.m[1] = tempDet2 * ogMat4InvDet;

	//02 (+)
	B_Mat3 tempMat02(m4.m[4], m4.m[5], m4.m[7],
					 m4.m[8], m4.m[9], m4.m[11],
					 m4.m[12], m4.m[13], m4.m[15]);
	tempDet3 = tempMat02.DeterminantMat3(tempMat02);
	tempMat4.m[2] = tempDet3 * ogMat4InvDet;

	//03 (-)
	B_Mat3 tempMat03(m4.m[5], m4.m[6], m4.m[7],
					 m4.m[9], m4.m[10], m4.m[11],
					 m4.m[13], m4.m[14], m4.m[15]);
	tempDet4 = tempMat03.DeterminantMat3(tempMat03);
	tempMat4.m[3] = tempDet4 * ogMat4InvDet;

//--------------------------------------------------------------
//ROW 2
	//10 (-)
	B_Mat3 tempMat10(m4.m[1], m4.m[2], m4.m[3],
					 m4.m[9], m4.m[10], m4.m[11],
					 m4.m[13], m4.m[14], m4.m[15]);
	tempDet5 = tempMat10.DeterminantMat3(tempMat10);
	tempMat4.m[4] = tempDet5 * ogMat4InvDet;

	//11 (+)
	B_Mat3 tempMat11(m4.m[0], m4.m[2], m4.m[3],
					 m4.m[8], m4.m[10], m4.m[11],
					 m4.m[12], m4.m[14], m4.m[15]);
	tempDet6 = tempMat11.DeterminantMat3(tempMat11);
	tempMat4.m[5] = tempDet6 * ogMat4InvDet;

	//12 (-)
	B_Mat3 tempMat12(m4.m[0], m4.m[1], m4.m[3],
					 m4.m[8], m4.m[9], m4.m[11],
					 m4.m[12], m4.m[13], m4.m[15]);
	tempDet7 = tempMat12.DeterminantMat3(tempMat12);
	tempMat4.m[6] = tempDet7 * ogMat4InvDet;

	//13 (+)
	B_Mat3 tempMat13(m4.m[0], m4.m[1], m4.m[2],
					 m4.m[8], m4.m[9], m4.m[10],
					 m4.m[12], m4.m[13], m4.m[14]);
	tempDet8 = tempMat13.DeterminantMat3(tempMat13);
	tempMat4.m[7] = tempDet8 * ogMat4InvDet;

//--------------------------------------------------------------
//ROW 3
	//20 (+)
	B_Mat3 tempMat20(m4.m[1], m4.m[2], m4.m[3],
					 m4.m[5], m4.m[6], m4.m[7],
					 m4.m[13], m4.m[14], m4.m[15]);
	tempDet9 = tempMat20.DeterminantMat3(tempMat20);
	tempMat4.m[8] = tempDet9 * ogMat4InvDet;

	//21 (-)
	B_Mat3 tempMat21(m4.m[0], m4.m[2], m4.m[3],
					 m4.m[4], m4.m[6], m4.m[7],
					 m4.m[12], m4.m[14], m4.m[15]);
	tempDet10 = tempMat21.DeterminantMat3(tempMat21);
	tempMat4.m[9] = tempDet10 * ogMat4InvDet;

	//22 (+)
	B_Mat3 tempMat22(m4.m[0], m4.m[1], m4.m[3],
					 m4.m[4], m4.m[5], m4.m[7],
					 m4.m[12], m4.m[13], m4.m[15]);
	tempDet11 = tempMat22.DeterminantMat3(tempMat22);
	tempMat4.m[10] = tempDet11 * ogMat4InvDet;

	//23 (-)
	B_Mat3 tempMat23(m4.m[0], m4.m[1], m4.m[2],
					 m4.m[4], m4.m[5], m4.m[6],
					 m4.m[12], m4.m[13], m4.m[14]);
	tempDet12 = tempMat23.DeterminantMat3(tempMat23);
	tempMat4.m[11] = tempDet12 * ogMat4InvDet;

//--------------------------------------------------------------
//ROW 4
	//30 (-)
	B_Mat3 tempMat30(m4.m[1], m4.m[2], m4.m[3],
					 m4.m[5], m4.m[6], m4.m[7],
					 m4.m[9], m4.m[10], m4.m[11]);
	tempDet13 = tempMat30.DeterminantMat3(tempMat30);
	tempMat4.m[12] = tempDet13 * ogMat4InvDet;

	//31 (+)
	B_Mat3 tempMat31(m4.m[0], m4.m[2], m4.m[3],
					 m4.m[4], m4.m[6], m4.m[7],
					 m4.m[8], m4.m[10], m4.m[11]);
	tempDet14 = tempMat31.DeterminantMat3(tempMat31);
	tempMat4.m[13] = tempDet14 * ogMat4InvDet;

	//32 (-)
	B_Mat3 tempMat32(m4.m[0], m4.m[1], m4.m[3],
					 m4.m[4], m4.m[5], m4.m[7],
					 m4.m[8], m4.m[9], m4.m[11]);
	tempDet15 = tempMat32.DeterminantMat3(tempMat32);
	tempMat4.m[14] = tempDet15 * ogMat4InvDet;

	//33 (+)
	B_Mat3 tempMat33(m4.m[0], m4.m[1], m4.m[2],
					 m4.m[4], m4.m[5], m4.m[6],
					 m4.m[8], m4.m[9], m4.m[10]);
	tempDet16 = tempMat33.DeterminantMat3(tempMat33);
	tempMat4.m[15] = tempDet16 * ogMat4InvDet;

	tempMat4 = tempMat4.TransposeMat4(tempMat4);

	return tempMat4;

}

//-----------------------------------------------------
//Rotations

//Mat4x4 X Rotate
B_Mat4 B_Mat4::B_Mat4RotateX(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);

	//B_Mat4 tempMat4;

	//m[0] = 1.0;	m[1] = 0.0;	m[2] = 0.0;	m[3] = 0.0;
	//m[4] = 0.0;	m[5] = c;	m[6] = -s;	m[7] = 0.0;
	//m[8] = 0.0;	m[9] = s;	m[10] = c;	m[11] = 0.0;
	//m[12] = 0.0;	m[13] = 0.0;	m[14] = 0.0;	m[15] = 1.0;

	m[0] = 1.0;  m[1] = 0.0;  m[2] = 0.0;  m[3] = 0.0;
	m[4] = 0.0;  m[5] = c;    m[6] = -s;   m[7] = 0.0;
	m[8] = 0.0;  m[9] = s;    m[10] = c;   m[11] = 0.0;
	m[12] = 0.0; m[13] = 0.0; m[14] = 0.0; m[15] = 1.0;

		return B_Mat4(m[0], m[1], m[2], m[3],
					  m[4], m[5], m[6], m[7],
					  m[8], m[9], m[10], m[11],
					  m[12], m[13], m[14], m[15]);
}

//Mat4x4 Y Rotate
B_Mat4 B_Mat4::B_Mat4RotateY(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);


	/*m[0] = c;	m[1] = 0.0;	m[2] = s;	m[3] = 0.0;
	m[4] = 0.0;	m[5] = 1.0;	m[6] = 0.0;	m[7] = 0.0;
	m[8] = -s;	m[9] = 0.0;	m[10] = c;	m[11] = 0.0;
	m[12] = 0.0;	m[13] = 0.0;	m[14] = 0.0;	m[15] = 1.0;*/

	m[0] = c;    m[1] = 0.0;  m[2] = s;    m[3] = 0.0;
	m[4] = 0.0;  m[5] = 1.0;  m[6] = 0.0;  m[7] = 0.0;
	m[8] = -s;   m[9] = 0.0;  m[10] = c;   m[11] = 0.0;
	m[12] = 0.0; m[13] = 0.0; m[14] = 0.0; m[15] = 1.0;

		return B_Mat4(m[0], m[1], m[2], m[3],
					  m[4], m[5], m[6], m[7],
					  m[8], m[9], m[10], m[11],
					  m[12], m[13], m[14], m[15]);
}

//Mat4x4 Z Rotate
B_Mat4 B_Mat4::B_Mat4RotateZ(float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);


	//m[0] = c;	m[1] = -s;	m[2] = 0.0;	m[3] = 0.0;
	//m[4] = s;	m[5] = c;	m[6] = 0.0;	m[7] = 0.0;
	//m[8] = 0.0;	m[9] = 0.0;	m[10] = 1.0;	m[11] = 0.0;
	//m[12] = 0.0;	m[13] = 0.0;	m[14] = 0.0;	m[15] = 1.0;

	m[0] = c;    m[1] = 0.0;  m[2] = s;    m[3] = 0.0;
	m[4] = 0.0;  m[5] = 1.0;  m[6] = 0.0;  m[7] = 0.0;
	m[8] = -s;   m[9] = 0.0;  m[10] = c;   m[11] = 0.0;
	m[12] = 0.0; m[13] = 0.0; m[14] = 0.0; m[15] = 1.0;

	return B_Mat4(m[0], m[1], m[2], m[3],
				  m[4], m[5], m[6], m[7],
				  m[8], m[9], m[10], m[11],
				m[12], m[13], m[14], m[15]);
}


//Mat4x4 Translations

//Vec3 Translation
void B_Mat4::B_Mat4Translate(const b_math::b_vectors::B_Vec3 &trans)
{
	//m[12] = m[12] + trans.x;
	//m[13] = m[13] + trans.y;
	//m[14] = m[14] + trans.z;

	m[12] = m[12] + trans.x;
	m[13] = m[13] + trans.y;
	m[14] = m[14] + trans.z;
}

//3 Floats Translations
void B_Mat4::B_Mat4Translate(float transx, float transy, float transz)
{
	/*m[12] = m[12] + transx;
	m[13] = m[13] + transy;
	m[14] = m[14] + transz;*/

	m[12] = m[12] + transx;
	m[13] = m[13] + transy;
	m[14] = m[14] + transz;
}

//Create a Perspective Matrix
void B_Mat4::makePerspective(B_Mat4 mat4, float fovyRadians, float aspectRatio, 
	float znear, float zfar)
{
	//B_Mat4 ret;

	// validate parameters
	if ((fovyRadians > 0.0f) && (fovyRadians < (float)PI) && 
		(aspectRatio > 0.0f) && 
		(znear > 0.0f) && (zfar > znear))
	{
		const float top = znear * tanf(fovyRadians*0.5f);
		const float right = aspectRatio * top;

		//mat4.m[0] =  znear / (right);
		//mat4.m[5] =  znear / (top);
		//mat4.m[10] = -(zfar + znear) / (zfar - znear);
		//mat4.m[14] = -2.0f*znear*zfar/ (zfar - znear);
		//mat4.m[11] = -1.0f;
		//mat4.m[15] = 0.0f;

		mat4.m[0] =  znear / (right);
		mat4.m[5] =  znear / (top);
		mat4.m[10] = -(zfar + znear) / (zfar - znear);
		mat4.m[14] = -2.0f*znear*zfar/ (zfar - znear);
		mat4.m[11] = -1.0f;
		mat4.m[15] = 0.0f;

	}
	//return ret;
}

//Create a Perspective Matrix
const B_Mat4 B_Mat4::makePerspective(float left, float right, float bottom, float top, 
	float znear, float zfar)
{
	B_Mat4 ret;

	if ((right - left > 0.0f) && (top - bottom > 0.0f) && 
		(znear > 0.0f) && (zfar > znear))
	{
		//ret.m[0] =  2.0f*znear / (right - left);
		//ret.m[5] =  2.0f*znear / (top - bottom);
		//ret.m[8] =  (right + left) / (right - left);
		//ret.m[9] =  (top + bottom) / (top - bottom);
		//ret.m[10] = -(zfar + znear) / (zfar - znear);
		//ret.m[14] = -2.0f*znear*zfar/ (zfar - znear);
		//ret.m[11] = -1.0f;
		//ret.m[15] = 0.0f;

		ret.m[0] =  2.0f*znear / (right - left);
		ret.m[5] =  2.0f*znear / (top - bottom);
		ret.m[8] =  (right + left) / (right - left);
		ret.m[9] =  (top + bottom) / (top - bottom);
		ret.m[10] = -(zfar + znear) / (zfar - znear);
		ret.m[14] = -2.0f*znear*zfar/ (zfar - znear);
		ret.m[11] = -1.0f;
		ret.m[15] = 0.0f;
	}
	return ret;
}

//Create Orthographic Matrix
const B_Mat4 B_Mat4::makeOrthographic(float width, float height, 
	float znear, float zfar)
{
	B_Mat4 ret;

	if ((width != 0.0f) && (height != 0.0f) && 
		(znear - zfar != 0.0f))
	{
		//ret.m[0] =  2.0f*znear / (width);
		//ret.m[5] =  2.0f*znear / (height);
		//ret.m[10] = -2.0f / (zfar - znear);
		//ret.m[14] = -(zfar + znear) / (zfar - znear);

		ret.m[0] =  2.0f*znear / (width);
		ret.m[5] =  2.0f*znear / (height);
		ret.m[10] = -2.0f / (zfar - znear);
		ret.m[14] = -(zfar + znear) / (zfar - znear);
	}
	return ret;
}

//Create Orthographic Matrix
const B_Mat4 B_Mat4::makeOrthographic(float left, float right, float bottom, float top, 
	float znear, float zfar)
{
	B_Mat4 ret;

	if ((right - left != 0.0f) && (top - bottom != 0.0f) && 
		(znear - zfar != 0.0f))
	{
		//ret.m[0] =  2.0f*znear / (right - left);
		//ret.m[5] =  2.0f*znear / (top - bottom);
		//ret.m[10] = -2.0f / (zfar - znear);
		//ret.m[12] = -(right + left) / (right - left);
		//ret.m[13] = -(top + bottom) / (top - bottom);
		//ret.m[14] = -(zfar + znear) / (zfar - znear);

		ret.m[0] =  2.0f*znear / (right - left);
		ret.m[5] =  2.0f*znear / (top - bottom);
		ret.m[10] = -2.0f / (zfar - znear);
		ret.m[12] = -(right + left) / (right - left);
		ret.m[13] = -(top + bottom) / (top - bottom);
		ret.m[14] = -(zfar + znear) / (zfar - znear);
	}
	return ret;
}


////Have an object look at another object
B_Mat4 B_Mat4::ObjectLookAt(b_graphics::b_parsers::ObjLoader *obj, b_math::b_vectors::B_Vec3 position, b_math::b_vectors::B_Vec3 worldUp, b_math::b_vectors::B_Vec3 focalPoint)
{
		
	/*	YOU SHOULD REMEMBER THIS FROM LAST TERM: 
		"FRENET FRAME"
	
					c1 = j = Up
							o
							|	
							|  . (Dir)
							| .
							|.
		c3 = E = position	X----------o  c0 = i = Right
						   /
						  /
						 o
		c2 = k = -(Direction)
	*/

	B_Mat4 ret;

	// //set position
	ret.c3.xyz = obj->position;
	//obj->position = position;
	//ret.c3.xyz.setEqualTo(obj->position);

	//// set direction
	ret.c2.xyz = ret.c2.xyz.Normalize(position - focalPoint);

	//// set up
	ret.c1.xyz = b_math::b_vectors::B_Vec3(0.0f, 1.0f, 0.0f);
	//ret.c1.xyz = ret.c1.xyz.crossNormalize(ret.c2.xyz, ret.c0.xyz);

	//// set right
	ret.c0.xyz = ret.c0.xyz.Cross(ret.c1.xyz, ret.c2.xyz);
	ret.c0.xyz.Normalize();

	//ret.c0.xyz = ret.c0.xyz.crossNormalize(worldUp, ret.c2.xyz);


	//// done
	return ret;
}

//B_Mat4 B_Mat4::ObjectLookAt(Camera3D *cam, B_Vec3 position, B_Vec3 worldUp, B_Vec3 focalPoint)
//{
//		
//	/*	YOU SHOULD REMEMBER THIS FROM LAST TERM: 
//		"FRENET FRAME"
//	
//					c1 = j = Up
//							o
//							|	
//							|  . (Dir)
//							| .
//							|.
//		c3 = E = position	X----------o  c0 = i = Right
//						   /
//						  /
//						 o
//		c2 = k = -(Direction)
//	*/
//
//	B_Mat4 ret;
//
//	// //set position
//	ret.c3.xyz = cam->pos;
//	//obj->position = position;
//	//ret.c3.xyz.setEqualTo(cam->pos);
//
//	//// set direction
//	ret.c2.xyz = c2.xyz.Normalize(position - focalPoint);
//
//	//// set right
//	ret.c0.xyz = c0.xyz.crossNormalize(worldUp, c2.xyz);
//
//	//// set up
//	ret.c1.xyz = c1.xyz.crossNormalize(c2.xyz, c0.xyz);
//
//	//// done
//	return ret;
//}


//Make Euler Rotations on a Mat4
B_Mat4 B_Mat4::B_Mat4RotateEulerXYZ(float xangle, float yangle, float zangle)
{
	B_Mat4 tempMat4 = B_Mat4( B_Mat4RotateZ(zangle) * B_Mat4RotateY(yangle) * B_Mat4RotateX(xangle));

	//m[0] = m[0];  m[1] = m[1];  m[2] = m[2];  m[3] = m[3];
	//m[4] = m[4];  m[5] = m[5];  m[6] = m[6];  m[7] = m[7];
	//m[8] = m[8];  m[9] = m[9];  m[10] = m[10]; m[11] = m[11];
	//m[12] = m[12]; m[13] = m[13]; m[14] = m[14]; m[15] = m[15];

	return tempMat4;
}

//Make a Transform Mat4
B_Mat4 B_Mat4::B_Mat4MakeTransform(B_Mat3 r, b_math::b_vectors::B_Vec3 t)
{
	B_Mat4 tempMat4 = B_Mat4( b_math::b_vectors::B_Vec4(r.m[0], r.m[1], r.m[2], 0), b_math::b_vectors::B_Vec4(r.m[3], r.m[4], r.m[5], 0), b_math::b_vectors::B_Vec4(r.m[6], r.m[7], r.m[8], 0), b_math::b_vectors::B_Vec4(t, 1)  ); 

	/*m[0] = m[0];  m[1] = m[1];  m[2] = m[2];  m[3] = m[3];
	m[4] = m[4];  m[5] = m[5];  m[6] = m[6];  m[7] = m[7];
	m[8] = m[8];  m[9] = m[9];  m[10] = m[10]; m[11] = m[11];
	m[12] = m[12]; m[13] = m[13]; m[14] = m[14]; m[15] = m[15];*/

	return tempMat4;
}

B_Mat4 B_Mat4::B_Mat4MakeTransform(B_Mat3 r, float s, b_math::b_vectors::B_Vec3 t)
{
	r = r*s;

	B_Mat4 tempMat4 = B_Mat4(B_Mat4MakeTransform(r, t));

	//m[0] = m[0];  m[1] = m[1];  m[2] = m[2];  m[3] = m[3];
	//m[4] = m[4];  m[5] = m[5];  m[6] = m[6];  m[7] = m[7];
	//m[8] = m[8];  m[9] = m[9];  m[10] = m[10]; m[11] = m[11];
	//m[12] = m[12]; m[13] = m[13]; m[14] = m[14]; m[15] = m[15];

	return tempMat4;
}

B_Mat4 B_Mat4::B_Mat4TransformInverseUniformScale(B_Mat4 &mat4)
{
	B_Mat3 tempMat3 = B_Mat3(mat4.m[0], mat4.m[1], mat4.m[2],
							 mat4.m[4], mat4.m[5], mat4.m[6],
							 mat4.m[8], mat4.m[9], mat4.m[10]);

	B_Mat3 rs = rs.B_Mat3InverseUniformScale(tempMat3);
	
	//FIX THiS CRAP***********************************************************************
	//Need to fix negative problem and add vec3 * float? or mat3 * float maybe?

	B_Mat4 tempMat4 = B_Mat4MakeTransform(rs, -1.0f * (rs * b_math::b_vectors::B_Vec3(mat4.m[12], mat4.m[13], mat4.m[14]))  );

	/*m[0] = m[0];  m[1] = m[1];  m[2] = m[2];  m[3] = m[3];
	m[4] = m[4];  m[5] = m[5];  m[6] = m[6];  m[7] = m[7];
	m[8] = m[8];  m[9] = m[9];  m[10] = m[10]; m[11] = m[11];
	m[12] = m[12]; m[13] = m[13]; m[14] = m[14]; m[15] = m[15];*/

	return tempMat4;


}

//Multiplication Operator
B_Mat4 B_Mat4::operator*(B_Mat4 mat4)
{
	return B_Mat4( (m[0]*mat4.m[0]  + m[1]*mat4.m[4]  + m[2]*mat4.m[8]  + m[3]*mat4.m[12]),  (m[0]*mat4.m[1]  + m[1]*mat4.m[5]  + m[2]*mat4.m[9]  + m[3]*mat4.m[13]),  (m[0]*mat4.m[2]  + m[1]*mat4.m[6]  + m[2]*mat4.m[10]  + m[3]*mat4.m[14]),  (m[0]*mat4.m[3]  + m[1]*mat4.m[7]  + m[2]*mat4.m[11] + m[3]*mat4.m[15]),
				   (m[4]*mat4.m[0]  + m[5]*mat4.m[4]  + m[6]*mat4.m[8]  + m[7]*mat4.m[12]),  (m[4]*mat4.m[1]  + m[5]*mat4.m[5]  + m[6]*mat4.m[9]  + m[7]*mat4.m[13]),  (m[4]*mat4.m[2]  + m[5]*mat4.m[6]  + m[6]*mat4.m[10]  + m[7]*mat4.m[14]),  (m[4]*mat4.m[3]  + m[5]*mat4.m[7]  + m[6]*mat4.m[11] + m[7]*mat4.m[15]),
				   (m[8]*mat4.m[0]  + m[9]*mat4.m[4]  + m[10]*mat4.m[8] + m[11]*mat4.m[12]), (m[8]*mat4.m[1]  + m[9]*mat4.m[5]  + m[10]*mat4.m[9] + m[11]*mat4.m[13]), (m[8]*mat4.m[2]  + m[9]*mat4.m[6]  + m[10]*mat4.m[10] + m[11]*mat4.m[14]), (m[8]*mat4.m[3]  + m[9]*mat4.m[7]  + m[10]*mat4.m[11] + m[11]*mat4.m[15]),
				   (m[12]*mat4.m[0] + m[13]*mat4.m[4] + m[14]*mat4.m[8] + m[15]*mat4.m[12]), (m[12]*mat4.m[1] + m[13]*mat4.m[5] + m[14]*mat4.m[9] + m[15]*mat4.m[13]), (m[12]*mat4.m[2] + m[13]*mat4.m[6] + m[14]*mat4.m[10] + m[15]*mat4.m[14]), (m[12]*mat4.m[3] + m[13]*mat4.m[7] + m[14]*mat4.m[11] + m[15]*mat4.m[15]));
}
