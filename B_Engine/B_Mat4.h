#ifndef _B_MAT4_H
#define _B_MAT4_H

#include "B_Mat3.h"
#include "B_Vec3.h"
#include "B_Vec4.h"
#include "ObjLoad.h"
//#include "Camera3D.h"


namespace b_math
{
	namespace b_matrices
	{

		class B_Mat4
		{
		public:

			B_Mat4(void);
			B_Mat4(float m0, float m1, float m2, float m3, 
				float m4, float m5, float m6, float m7,
				float m8, float m9, float m10, float m11,
				float m12, float m13, float m14, float m15);
			B_Mat4(B_Mat4 &m4);
			B_Mat4(b_math::b_vectors::B_Vec4 &v1, b_math::b_vectors::B_Vec4 &v2, b_math::b_vectors::B_Vec4 &v3, b_math::b_vectors::B_Vec4 &v4);
			B_Mat4(float mat[16]);

			~B_Mat4(void);

			B_Mat4 InverseMat4(B_Mat4 &m4);
			B_Mat4 TransposeMat4(B_Mat4 &m4);
			float DeterminantMat4(B_Mat4 &m4);
			float invDeterminantMat4(B_Mat4 &m4);

			void B_Mat4Scale(float scaleValue);
			void B_Mat4Translate(const b_math::b_vectors::B_Vec3 &trans);
			void B_Mat4Translate(float transx, float transy, float transz);

			B_Mat4 B_Mat4RotateX(float angle);
			B_Mat4 B_Mat4RotateY(float angle);
			B_Mat4 B_Mat4RotateZ(float angle);

			B_Mat4 B_Mat4RotateEulerXYZ(float xangle, float yangle, float zangle);

			B_Mat4 B_Mat4MakeTransform(B_Mat3 r, b_math::b_vectors::B_Vec3 t);
			B_Mat4 B_Mat4MakeTransform(B_Mat3 r, float s, b_math::b_vectors::B_Vec3 t);
			B_Mat4 B_Mat4TransformInverseUniformScale(B_Mat4 &mat4);

			//Operators
			B_Mat4 operator*(B_Mat4 mat4);

			// utility to make basic projection matrix
			void makePerspective(B_Mat4 mat4, float fovyRadians, float aspectRatio, 
				float znear, float zfar);
			const B_Mat4 makePerspective(float left, float right, float bottom, float top, 
				float znear, float zfar);
			const B_Mat4 makeOrthographic(float width, float height, 
				float znear, float zfar);
			const B_Mat4 makeOrthographic(float left, float right, float bottom, float top, 
				float znear, float zfar);

			B_Mat4 ObjectLookAt(b_graphics::b_parsers::ObjLoader *obj, b_math::b_vectors::B_Vec3 position, b_math::b_vectors::B_Vec3 worldUp, b_math::b_vectors::B_Vec3 focalPoint);
			//B_Mat4 ObjectLookAt(Camera3D *cam, B_Vec3 position, B_Vec3 worldUp, B_Vec3 focalPoint);


			b_math::b_vectors::B_Vec4 c0, c1, c2, c3;

			/*struct{ float m00, m01, m02, m03, 
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33;
			};*/

			//float mat4_4[4][4];
			float m[16];

		};
	}
}


#endif

