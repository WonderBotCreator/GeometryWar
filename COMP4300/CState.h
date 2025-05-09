#pragma once
#include <string>
#include "Components.h"

class CState : public Components
{
public:
	std::string state = "jumping";
	CState() = default;
	CState(const std::string& s)
		:state(s)
	{

	}
};

