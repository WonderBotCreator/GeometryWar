#include "SceneMenu.h"
#include "GameEngine.h"

void SceneMenu::init()
{
	registerAction(sf::Keyboard::Up, "UP");
	registerAction(sf::Keyboard::Down, "Down");
	registerAction(sf::Keyboard::Enter, "ChangeScene");

	

	m_menuText.setCharacterSize(36);
	m_menuText.setFont(m_game->assets().getFont("roboto"));


	for (int i = 0; i < 3; i++)
	{
		m_menuStrings.push_back("Level "+ std::to_string(i+1));
	}
}

void SceneMenu::update()
{
	sRender();
}

void SceneMenu::onEnd()
{
}

void SceneMenu::sDoAction(const Action& action)
{
	if (action.type() == "START")
	{
		if (action.name() == "UP")
		{
			m_selectedMenuIndex++;
			if (m_selectedMenuIndex >= m_menuStrings.size())
			{
				m_selectedMenuIndex = 0;
			}
			
		}
		else if (action.name() == "DOWN")
		{
			m_selectedMenuIndex--;
			if (m_selectedMenuIndex < 0)
			{
				m_selectedMenuIndex = m_menuStrings.size() - 1;
			}
		}
	}
	else if (action.type() == "END")
	{
		if (action.name() == "UP")
		{
			
		}
		else if (action.name() == "DOWN")
		{

		}
	}
}

SceneMenu::SceneMenu(GameEngine* gameEngine)
	:Scene(gameEngine)
{
	init();
}

void SceneMenu::sRender()
{
	for (size_t i = 0; i < m_menuStrings.size(); i++)
	{
		m_menuText.setString(m_menuStrings[i]);
		m_menuText.setPosition(m_game->window().getSize().x / 2.0f, m_menuText.getCharacterSize() * i + 20);
		m_game->window().draw(m_menuText);
	}
}
