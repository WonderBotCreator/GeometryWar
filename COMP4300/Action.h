#pragma once

#include <iostream>

class Action
{
	std::string m_name = "NONE";
	std::string m_type = "NONE";

public:

	Action() = default;
	Action(const std::string& name, const std::string& type)
		:m_name(name)
		,m_type(type)
	{

	}




	const std::string& name() const;
	std::string toString() const;
	const std::string& type() const;

};

