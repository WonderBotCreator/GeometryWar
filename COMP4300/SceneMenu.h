#pragma once

#include "Scene.h"
#include <map>
#include <memory>
#include <deque>



class SceneMenu: public Scene
{
protected:
	std::string m_title;
	std::vector<std::string> m_menuStrings;
	std::vector<std::string> m_levelPaths;
	sf::Text m_menuText;
	size_t m_selectedMenuIndex = 0;

	void init();
	void onEnd();
	void update();
	void sDoAction(const Action& action);

public:
	SceneMenu(GameEngine* gameEngine);
	void sRender();
	
};

