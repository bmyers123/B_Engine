#ifndef B_VEC4_H
#define B_VEC4_H

#include "B_Vec3.h"

namespace b_math
{
	namespace b_vectors
	{

		class B_Vec4
		{
		public:
			B_Vec4();
			B_Vec4(float V);
			B_Vec4(float X, float Y, float Z, float W);
			B_Vec4(B_Vec3 vec3, float W);
			B_Vec4(const float *Vp);

			~B_Vec4();

			B_Vec4 operator+(const B_Vec4 &v4);//{return B_Vec3(x + v3.x, y + v3.y, z + v3.z);}
			B_Vec4 operator-(const B_Vec4 &v4);//{return B_Vec3(x - v3.x, y - v3.y, z - v3.z);}
			B_Vec4 operator/(const B_Vec4 &v4);//{return B_Vec3(x/v3.x, y/v3.y, z/v3.z);}
			B_Vec4 operator*(const B_Vec4 &v4);
			void operator+=(const B_Vec4 &v4);
			void operator-=(const B_Vec4 &v4);
			void operator/=(const B_Vec4 &v4);
			void operator*=(const B_Vec4 &v4);

			const float operator[](unsigned char r) const;
			float &operator[](unsigned char r);

			float dotProductV4(const B_Vec4 &v0, const B_Vec4 &v1);


			//private:

			float x, y, z, w;
			float r, g, b, a;
			float s, t, p, q;

			B_Vec3 xyz;

			float v[4];

		};

	}
}

//static const B_Vec4 v4zero;
//static const B_Vec4 v4x(1, 0, 0, 0);
//static const B_Vec4 v4y(0, 1, 0, 0);
//static const B_Vec4 v4z(0, 0, 1, 0);
//static const B_Vec4 v4w(0, 0, 0, 1);

#endif