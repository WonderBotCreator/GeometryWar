#include "EditableRect.h"

void EditableRect::move(int screenWidth, int screenHeight)
{

    rect.setFillColor(sf::Color(colorRGB[0] * 255, colorRGB[1] * 255, colorRGB[2] * 255));
    rect.setSize(sf::Vector2f(rectWidth, rectHeight));

    if (rectSpeedX > 0)
    {
        if (rect.getPosition().x + rectWidth > screenWidth)
        {
            rectSpeedX *= -1;
        }
        rect.setPosition(rect.getPosition().x + rectSpeedX, rect.getPosition().y + rectSpeedY);
    }

    if (rectSpeedX < 0)
    {
        if (rect.getPosition().x < 0)
        {
            rectSpeedX *= -1;
        }
        rect.setPosition(rect.getPosition().x + rectSpeedX, rect.getPosition().y + rectSpeedY);
    }

    if (rectSpeedY > 0)
    {
        if (rect.getPosition().y + rectHeight > screenHeight)
        {
            rectSpeedY *= -1;
        }
        rect.setPosition(rect.getPosition().x + rectSpeedX, rect.getPosition().y + rectSpeedY);
    }

    if (rectSpeedY < 0)
    {
        if (rect.getPosition().y < 0)
        {
            rectSpeedY *= -1;
        }
        rect.setPosition(rect.getPosition().x + rectSpeedX, rect.getPosition().y + rectSpeedY);
    }

    text.setPosition(rect.getPosition().x + (rectWidth/2.0f) - (text.getLocalBounds().width / 2.0f), rect.getPosition().y + (rectHeight/2.0f) - (text.getCharacterSize() / 2.0f));
}

void EditableRect::draw(sf::RenderWindow& window)
{
    if (drawRect)
    {
        window.draw(rect);
    }

    if (drawText)
    {
        window.draw(text);
    }
}
