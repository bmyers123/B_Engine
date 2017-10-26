#ifndef _B_MAT3_H
#define _B_MAT3_H

#include "B_Vec3.h"

namespace b_math
{
	namespace b_matrices
	{

		class B_Mat3
		{
		public:
			B_Mat3(void);
			B_Mat3(float M00, float M01, float M02, float M10, float M11, float M12, float M20, float M21, float M22);
			B_Mat3(B_Mat3 &m3);
			B_Mat3(float mat3);
			B_Mat3(b_math::b_vectors::B_Vec3 &v_row1, b_math::b_vectors::B_Vec3 &v_row2, b_math::b_vectors::B_Vec3 &v_row3);


			~B_Mat3(void);

			void setMat3ToIdentity();

			B_Mat3 InverseMat3(B_Mat3 &m3);
			B_Mat3 TransposeMat3();
			float DeterminantMat3(B_Mat3 &m3);
			float invDeterminantMat3(B_Mat3 &m3);

			void B_Mat3Scale(float scaleValue);
			void B_Mat3Translate(const b_math::b_vectors::B_Vec3 &trans);
			void B_Mat3Translate(float transx, float transy, float transz);

			B_Mat3 B_Mat3RotateX(float angle);
			B_Mat3 B_Mat3RotateY(float angle);
			B_Mat3 B_Mat3RotateZ(float angle);

			B_Mat3 B_Mat3RotateEulerXYZ(float xangle, float yangle, float zangle);

			B_Mat3 B_Mat3InverseUniformScale(B_Mat3 &mat3);


			B_Mat3 operator*(B_Mat3 &mat3);
			B_Mat3 operator*(float f);
			//B_Mat3 operator*(float f);
			float operator*(b_math::b_vectors::B_Vec3 &v3);


			//struct{float m00, m01, m02, 
			//			 m10, m11, m12,
			//			 m20, m21, m22;
			//	};

			//float mat3_3[4][4];
			float m[9];


		};

	}
}
//B_Vec3 operator*(B_Vec3 &v3, B_Mat3 &m3)
//{
//	return B_Vec3( (v3.x*m3.m00 + v3.y*m3.m10 + v3.z*m3.m20), (v3.x*m3.m01 + v3.y*m3.m11 + v3.z*m3.m21), (v3.x*m3.m02 + v3.y*m3.m12 + v3.z*m3.m22) );
//};


#endif