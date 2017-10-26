#ifndef _B_VEC2_H
#define _B_VEC2_H


namespace b_math
{
	namespace b_vectors
	{

		class B_Vec2
		{
		public:
			B_Vec2();
			B_Vec2(float X, float Y);
			B_Vec2(const float *Vp);
			B_Vec2(const B_Vec2 &vec2);

			~B_Vec2(void);

			float GetLenghtVec2();
			B_Vec2 CrossProductVec2(B_Vec2 &v2);
			B_Vec2 NormalizeVec2(B_Vec2 &v2);
			float DotProductVec2(B_Vec2 &v2);

			//Negations
			void NegateVec2XY();
			void NegateVec2X();
			void NegateVec2Y();

			//Operators
			B_Vec2 operator+(const B_Vec2 &v2);//{return B_Vec2(x + v2.x, y + v2.y);}
			B_Vec2 operator-(const B_Vec2 &v2);//{return B_Vec2(x - v2.x, y - v2.y);}
			B_Vec2 operator/(const B_Vec2 &v2);//{return B_Vec2(x/v2.x, y/v2.y);}
			B_Vec2 operator*(const B_Vec2 &v2);//{return B_Vec2(x * v2.x, y * v2.y);}

			B_Vec2 operator/(float f);
			B_Vec2 operator*(float f);

			const float operator[](unsigned char r) const;
			float &operator[](unsigned char r);

			void operator+=(const B_Vec2 &v2);
			void operator+=(const float &f);

			void operator-=(const B_Vec2 &v2);
			void operator/=(const B_Vec2 &v2);
			void operator*=(const B_Vec2 &v2);

			//Comparison Operators
			bool operator==(const B_Vec2 &v2);
			void operator=(const B_Vec2 &v2);

			/*	template<typename T>
			B_Vec2 &operator(std::vector<T>,*/ 

			float x, y;
			float v[2];
			static B_Vec2 tempVec2;

		};

	}
}



#endif

