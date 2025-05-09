#include "EditableCircle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void EditableCircle::move(int screenWidth, int screenHeight)
{
    
    circle.setFillColor(sf::Color(colorRGB[0]*255, colorRGB[1]*255, colorRGB[2]*255));
    circle.setPointCount(circleSegments);
    circle.setRadius(circleRadius);

    if (circleSpeedX > 0)
    {
        if (circle.getPosition().x + (circleRadius * 2) > screenWidth)
        {
            circleSpeedX *= -1;
        }
        circle.setPosition(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY);
    }

    if (circleSpeedX < 0)
    {
        if (circle.getPosition().x < 0)
        {
            circleSpeedX *= -1;
        }
        circle.setPosition(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY);
    }

    if (circleSpeedY > 0)
    {
        if (circle.getPosition().y + (circleRadius * 2) > screenHeight)
        {
            circleSpeedY *= -1;
        }
        circle.setPosition(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY);
    }

    if (circleSpeedY < 0)
    {
        if (circle.getPosition().y < 0)
        {
            circleSpeedY *= -1;
        }
        circle.setPosition(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY);
    }

    text.setPosition(circle.getPosition().x+circleRadius-(text.getLocalBounds().width/2.0f), circle.getPosition().y + circleRadius - (text.getCharacterSize() / 2.0f));
    //std::cout << text.getLocalBounds().width << "\n";
}

void EditableCircle::draw(sf::RenderWindow& window)
{
    if (drawCircle)
    {
        window.draw(circle);
    }

    if (drawText)
    {
        window.draw(text);
    }
    
}

void EditableCircle::setRadius(float radius)
{
    circleRadius = radius;
}

void EditableCircle::setSpeedX(float speedX)
{
    circleSpeedX = speedX;
}

void EditableCircle::setSpeedY(float speedY)
{
    circleSpeedY = speedY;
}

void EditableCircle::setDrawCircle(bool isDraw)
{
    drawCircle = isDraw;
}

void EditableCircle::setDrawText(bool isDraw)
{
    drawText = isDraw;
}

bool& EditableCircle::getDrawCircle()
{
    return drawCircle;
}

bool& EditableCircle::getDrawText()
{
    return drawText;
}

float& EditableCircle::getCircleRadius()
{
    return circleRadius;
}

float& EditableCircle::getCircleSegment()
{
    return circleSegments;
}

float* EditableCircle::getCircleColor()
{
    return colorRGB;
}

float& EditableCircle::getSpeedX()
{
    return circleSpeedX;
}

float& EditableCircle::getSpeedY()
{
    return circleSpeedY;
}

std::string EditableCircle::getCircleText()
{
    return texts;
}

