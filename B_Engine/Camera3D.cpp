#include "Engine.h"

using namespace b_graphics;
using namespace b_prefabs;

Camera3D::Camera3D(sf::Window* window)
{
	this->window = window;

	//Set some default values
	pos.x = pos.y = pos.z = 0.0f;
	forward.x = forward.y = forward.z = 0.0f;
	strafe.x = strafe.y = strafe.z = 0.0f;


	azemuth   = 0.0f;
	elevation = 0.0f;
}

void Camera3D::setWindow(sf::Window* window)
{
	this->window = window;
}

void Camera3D::Activate()
{
	projectionMat.makePerspective(projectionMat, 1.57f, float(window->getSize().x) / float(window->getSize().y), 2.0f, 1000.0f);
}

b_math::b_matrices::B_Mat4 Camera3D::Target(b_math::b_vectors::B_Vec3 &targetPos, sf::Vector2i diff, float zoom)
{	


	azemuth += float(diff.x)*0.1f;
	elevation += float(diff.y)*0.1f;

	forward.PolartoVector(azemuth, elevation, 1.0f);
	strafe.PolartoVector(azemuth+90.0f, 0.0f, 1.0f);
	up = strafe.Cross(forward);

	//forward = forward - zoom;

	forward.Normalize();
	strafe.Normalize();
	up.Normalize();


	//WORKS, DONT KNOW WHY, DON"T KNOW WHICH IS BETTER TO USE, USING THE OTHER INSTEAD.
	//projectionMat.B_Mat4Translate(-pos.x, -pos.y, -pos.z);	
	//Rotate the camera
	//projectionMat.B_Mat4RotateX(elevation);
	//glRotatef(elevation, 1.0f, 0.0f, 0.0f);
	//projectionMat.B_Mat4RotateY(azemuth);
	//glRotatef(azemuth, 0.0f, 1.0f, 0.0f);	
	//glTranslatef(-pos.x, -pos.y, -pos.z);


	return M = b_math::b_matrices::B_Mat4(strafe.x,  strafe.y,  strafe.z,  0,
					  up.x,		 up.y,		up.z,	   0,
					  forward.x, forward.y, forward.z, 0,
					  0,		 0,		    0,         1);



	//EXPERIMENT WITH THE ZOOM
	//return M = B_Mat4(strafe.x,  strafe.y,  strafe.z,  0,
	//			      up.x,		 up.y,		up.z,	   0,
	//			      forward.x, forward.y, forward.z, 0,
	//				  zoom,		 zoom,		zoom,         1);
	



	
	//THESE DO NOT WORK - Figure out why?
	//return M = B_Mat4(strafe.x, up.x, forward.x, 0,
	//				  strafe.y, up.y, forward.y, 0,
	//				  strafe.z, up.z, forward.z, 0,
	//				  0,          0,       0,         1);



	//return M = B_Mat4(rightVec.x,  rightVec.y,  rightVec.z, 0,
	//				  upVec.x,	   upVec.y,		upVec.z,	0,
	//				  viewVec.x,   viewVec.y,   viewVec.z,  0,
	//				  0,    0,    0,    1);


}