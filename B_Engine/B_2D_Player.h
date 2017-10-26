#ifndef _B_2D_PLAYER_H
#define _B_2D_PLAYER_H

#include "B_Vec2.h"

class B_2D_Player
{
public:
	B_2D_Player(void);

	B_2D_Player(float Player2DMass, float Player2DAccel, float Player2DTopSpeed){B_2DP_mass = Player2DMass; B_2DP_accel = Player2DAccel; B_2DP_topSpeed = Player2DTopSpeed;};
	//add constructor with all base attributes such as:

	/*

	- mass
	- topSpeed
	- Position
	- etc

	*/

	~B_2D_Player(void);

	//void setPlayerSprite(B_Sprites &sprite);

	void Jump(float dt);
	void DashLeft();
	void DashRight();


private:
//	B_Sprites B_2D_playerSprite;
	b_math::b_vectors::B_Vec2 player_Pos;

	float B_2DP_mass;
	float B_2DP_accel;
	float B_2DP_vel;
	float B_2DP_topSpeed;

};

#endif
