#pragma once

#include "Components.h"

class CInput : public Components
{
public:

	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;
	bool shoot = false;
	bool canShoot = true;
	bool canJump = true;

	CInput(){}
};

