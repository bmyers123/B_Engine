#ifndef _B_MAT2_H
#define _B_MAT2_H

namespace b_math
{
	namespace b_matrices
	{

		class B_Mat2
		{
		public:
			B_Mat2(void);
			~B_Mat2(void);
			B_Mat2(float M00, float M01, float M10, float M11);
			B_Mat2(B_Mat2 &m2);
			B_Mat2(float mat2);
			//B_Mat2(B_Vec2 &v_row1, B_Vec2 &v_row2);

			void setMat2toIdentity();

			float DeterminantMat2(B_Mat2 &m2);
			float invDeterminantMat2(B_Mat2 &m2);

			B_Mat2 InverseMat2(B_Mat2 &m2);
			B_Mat2 TransposeMat2(B_Mat2 &m2);

			struct{float m00, m01, m10, m11;};

		};
	}
}

#endif