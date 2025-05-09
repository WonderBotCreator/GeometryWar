#pragma once

#include <SFML/Graphics.hpp>

class EditableRect
{

	sf::RectangleShape rect;

	float rectWidth = 0.0f;
	float rectHeight = 0.0f;

	float rectSpeedX = 0.0f;
	float rectSpeedY = 0.0f;

	float positionX = 0.0f;
	float positionY = 0.0f;

	bool drawRect = true;
	bool drawText = true;

	int textSize = 0.0f;

	float colorRGB[3] = { 0.0f,0.0f, 0.0f };
	sf::Color color;
	sf::Text text;

public:
	EditableRect(){}
	EditableRect(float width, float height,float speedX, float speedY, float posX, float posY, float colorIn[3], const char textIn[], sf::Font& fontIn, int textSizeIn)
		:rectWidth(width), rectHeight(height), positionX(posX), positionY(posY),rectSpeedX(speedX), rectSpeedY(speedY), textSize(textSizeIn)
	{
		rect = sf::RectangleShape(sf::Vector2f(rectWidth, rectHeight));
		rect.setPosition(positionX, positionY);

		for (int i = 0; i < 3; i++)
		{
			colorRGB[i] = colorIn[i];
		}
		color = sf::Color(colorRGB[0] * 255, colorRGB[1] * 255, colorRGB[2] * 255);
		text = sf::Text(textIn, fontIn, textSize);
		text.setPosition(rect.getPosition().x, rect.getPosition().y);
	}

	void move(int screenWidth, int screenHeight);

	void draw(sf::RenderWindow& window);
};

