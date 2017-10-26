//---------------------------------------------
//
//Brayden Myers, 2014
//
//----------
//
//Created for general math uses in-game
//and for future engine builds.
//
//----------

#ifndef _B_VEC3_H
#define _B_VEC3_H

namespace b_math
{
	namespace b_vectors
	{

		class B_Vec3
		{
		public:

			//Constructors
			B_Vec3();
			B_Vec3(float xyz);
			B_Vec3(float X, float Y, float Z);
			B_Vec3(const B_Vec3 &v3);
			B_Vec3(const float *Vp);

			//Deconstructor
			~B_Vec3(void);

			//Mathematical Vector Functions
			//Negating a vector
			void Negate(); 

			//Cross Product
			B_Vec3 Cross(B_Vec3 &v3);
			B_Vec3 Cross(B_Vec3 &v3, B_Vec3 &v32);
			B_Vec3 crossNormalize(B_Vec3 &v3, B_Vec3 &v32);

			//Dot product
			float Dot(B_Vec3 &v); 
			float DotAngle(B_Vec3 &v3_1, B_Vec3 &v3_2);

			//Normalizing a vector
			B_Vec3 Normalize();
			B_Vec3 Normalize(B_Vec3 &v3);

			//Distance between two vec3s
			float GetDistanceFrom(B_Vec3 &v3);
			float GetLengthVec3();

			//Rotations
			void RotateX(float angle);
			void RotateY(float angle);
			void RotateZ(float angle);

			//Conversions
			void PolartoVector(float azemuth, float elevation, float distance);
			B_Vec3 VectortoPolar(B_Vec3 target);

			//Mathematical Operators
			B_Vec3 operator+(const B_Vec3 &v3);//{return B_Vec3(x + v3.x, y + v3.y, z + v3.z);}
			B_Vec3 operator+(const float f);
			B_Vec3 operator-(const B_Vec3 &v3);//{return B_Vec3(x - v3.x, y - v3.y, z - v3.z);}
			B_Vec3 operator/(const B_Vec3 &v3);//{return B_Vec3(x/v3.x, y/v3.y, z/v3.z);}
			B_Vec3 operator*(const B_Vec3 &v3);//{return B_Vec3(x * v3.x, y * v3.y, z * v3.z);}

			//B_Vec3 returns with rhs floats
			B_Vec3 operator/(float f);
			B_Vec3 operator*(float f);
			//B_Vec3 operator*(B_Mat3 &m3);

			float operator*(B_Vec3 v3);

			void operator+=(const B_Vec3 &v3);
			void operator-=(const B_Vec3 &v3);
			void operator/=(const B_Vec3 &v3);
			void operator*=(const B_Vec3 &v3);

			//Comparison Operators
			bool operator==(const B_Vec3 &v3);
			void operator=(const B_Vec3 &v3);
			void setEqualTo(B_Vec3 &v3);

			const float operator[](unsigned char r) const;
			float &operator[](unsigned char r);

			float x, y, z;
			float v[3];
			//float length;//necesary?

		private:

			static float B_cosAngle, B_sinAngle;
			//	static B_Vec3 tempV;

		};

	}
}

#endif