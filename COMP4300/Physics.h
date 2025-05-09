#pragma once

#include <iostream>
#include "Vec2.h"
#include "Entity.h"

class Physics
{
public:
	Vec2 getOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
	Vec2 getPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
};

