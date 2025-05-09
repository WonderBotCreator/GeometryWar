#pragma once

#include "Components.h"

class CBBox : public Components
{
public:
	Vec2 size;
	Vec2 halfSize;

	CBBox() = default;
	CBBox(const Vec2& s)
		:size(s), halfSize(s.x / 2, s.y / 2)
	{

	}
};

