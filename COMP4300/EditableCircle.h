#pragma once

#include <SFML/Graphics.hpp>

class EditableCircle
{
	sf::CircleShape circle;
    float circleRadius = 50;
    float circleSegments = 32;
    float circleSpeedX = 3.0f;
    float circleSpeedY = 0.5f;
    bool drawCircle = true;
    bool drawText = true;

    float positionX = 0.0f;
    float positionY = 0.0f;

    sf::Color color;
    sf::Text text;

    int textSize = 0.0f;

    float colorRGB[3] = { 0.0f,0.0f, 0.0f };

    std::string texts;
public:

    EditableCircle(){}

    EditableCircle(float radius, float segments, float speedX, float speedY, float posX, float posY, float colorIn[3],const char textIn[], sf::Font& fontIn, int textSizeIn)
        :circleRadius(radius),circleSegments(segments), circleSpeedX(speedX), circleSpeedY(speedY), positionX(posX), positionY(posY), textSize(textSizeIn)

    {
        circle = sf::CircleShape(circleRadius, circleSegments);
        circle.setPosition(positionX, positionY);
        for(int i = 0;i<3;i++)
        {
            colorRGB[i] = colorIn[i];
        }
        color = sf::Color(colorRGB[0]*255,colorRGB[1]*255, colorRGB[2]*255);
        //strcpy(textIn, texts);
        text = sf::Text(textIn, fontIn, textSize);
        texts = textIn;
        text.setPosition(circle.getPosition().x, circle.getPosition().y);
    }

    void move(int screenWidth, int screenHeight);

    void draw(sf::RenderWindow& window);

    void setRadius(float radius);
    void setSpeedX(float speedX);
    void setSpeedY(float speedY);
    void setDrawCircle(bool isDraw);
    void setDrawText(bool isDraw);

    bool& getDrawCircle();
    bool& getDrawText();

    float& getCircleRadius();
    float& getCircleSegment();

    float* getCircleColor();

    float& getSpeedX();
    float& getSpeedY();

    std::string getCircleText();
};

