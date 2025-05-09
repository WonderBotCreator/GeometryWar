#pragma once

#include "Components.h"

class CGravity: public Components
{
public:
	float gravity = 0;
	CGravity() = default;
	CGravity(float g)
		:gravity(g)
	{

	}
};

