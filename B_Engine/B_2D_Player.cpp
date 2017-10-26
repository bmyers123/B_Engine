#include "Engine.h"

//Default 2D Player Constructor
B_2D_Player::B_2D_Player(void)
{
	B_2DP_mass = B_2DP_accel = B_2DP_topSpeed = 0;
}

//2D Player Destructor
B_2D_Player::~B_2D_Player(void){}

//Jump Function
void B_2D_Player::Jump(float dt)
{

B_2DP_accel -= GRAVITY * dt;

B_2DP_vel += B_2DP_accel * dt;

//player_Pos.x += B_2DP_vel * dt;
player_Pos.y += B_2DP_vel * dt;

	// apply gravity
//acceleration.y -= gravity * frametime;
 
// update velocity
//velocity += acceleration * frameTime;
 
// update position

//position += velocity * frameTime;
}
