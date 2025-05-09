  #pragma once
#include "Vec2.h"
#include "Components.h"

class CTransform : public Components
{
public:
	Vec2 pos = { 0,0 };
	Vec2 velocity = { 0,0 };

	Vec2 prevPos = { 0,0 };
	Vec2 scale = { 1.0, 1.0 };

	float angle = 0;

	CTransform(){}
	CTransform(const Vec2& p)
		:pos(p)
	{

	}
	CTransform(const Vec2& p, const Vec2& v, float a)
		:pos(p), velocity(v), angle(a)
	{

	}
	CTransform(const Vec2& p, const Vec2& sp, const Vec2& sc, float a)
		:pos(p), prevPos(sp), scale(sc), angle(a)
	{

	}
};

