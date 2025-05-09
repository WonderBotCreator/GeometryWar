// COMP4300.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <fstream>

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "EditableCircle.h"
#include "EditableRect.h"
#include "Entity.h"
#include "CTransform.h"
#include "Assignment2.h"
#include "GameEngine.h"



int main()
{
    //GameEngine* gameEngine = new GameEngine("assets.txt");
    //gameEngine->run();
    Assignment2* assignment2 =  new Assignment2();
    assignment2->run();
    return 0;
}


