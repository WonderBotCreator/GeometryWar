#pragma once
#include <SFML/Graphics.hpp>
class CShape2
{
public:
	sf::CircleShape circle;
	CShape2() {}

	CShape2(float radius, int points)

	{

		circle = sf::CircleShape(radius, points);


	}
};

