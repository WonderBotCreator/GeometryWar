#pragma once

#include "Components.h"

class CLifespan: public Components
{
public:
	int lifespan = 0;
	int frameCreated = 0;
	CLifespan(int duration, int frame)
		:lifespan(duration), frameCreated(frame)
	{

	}
};

