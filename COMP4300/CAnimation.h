#pragma once

#include "Components.h"
class CAnimation: public Components
{
public:
	Animation animation;
	bool repeat = false;
	CAnimation() = default;
	CAnimation(const Animation& animation, bool r)
		:animation(animation), repeat(r)
	{
		 
	}
};

