#ifndef _CAMERA3D_
#define _CAMERA3D_

#include "B_Vec2.h"
#include "B_Vec3.h"
#include "B_Mat4.h"
#include "ObjLoad.h"

namespace b_graphics{
	namespace b_prefabs{

		class Camera3D
		{
		public:
			Camera3D();
			Camera3D(sf::Window* window);
			void Activate();
			b_math::b_matrices::B_Mat4 Target(b_math::b_vectors::B_Vec3 &targetPos, sf::Vector2i diff, float zoom);
			//void B_LookAt(B_Vec3 eyePos, B_Vec3 lookAtPos, B_Vec3 upVec, float zoom);

			void setWindow(sf::Window* window);


			sf::Vector2i diff;
			b_math::b_vectors::B_Vec3 pos;
			b_math::b_vectors::B_Vec3 forward;
			b_math::b_vectors::B_Vec3 strafe;
			b_math::b_vectors::B_Vec3 up;
			b_math::b_matrices::B_Mat4 projectionMat, viewMat, M;
			float azemuth;
			float elevation;

			sf::Window *window;
		};

	}
}

#endif