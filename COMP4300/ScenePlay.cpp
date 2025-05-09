#include "ScenePlay.h"

void ScenePlay::init(const std::string& levelPath)
{
	registerAction(sf::Keyboard::P, "PAUSE");
	registerAction(sf::Keyboard::Escape, "QUIT");
	registerAction(sf::Keyboard::T, "TOGGLE_TEXTURE");
	registerAction(sf::Keyboard::C, "TOGGLE_COLLISION");
	registerAction(sf::Keyboard::G, "TOGGLE_GRID");

	registerAction(sf::Keyboard::W, "UP");

	m_gridText.setCharacterSize(12);
	m_gridText.setFont(m_game->assets().getFont("Tech"));

	loadLevel(levelPath);
}

void ScenePlay::loadLevel(const std::string& filename)
{
	m_entityManager = EntityManager();
	spawnPlayer();

	auto brick = m_entityManager.addEntity("tile");

	brick->cAnimation = std::make_shared<CAnimation>(m_game->assets().getAnimation("Brick"), true);
	brick->cTransform = std::make_shared<CTransform>(Vec2(96, 480));
	//brick->addComponent<CAnimation>(m_game->assets().getAnimation("Brick"), true);
	//brick->addComponent<CTransform>(Vec2(96,480));


	/*if (brick->getComponent<CAnimation>().animation.getName() == "Brick")
	{
		std::cout << "This could be a good way of identifying if a tile is a brick\n";
	}*/

	/*if (brick->hasComponent<CAnimation>())
	{

	}

	brick->removeComponent<CAnimation>();*/

	auto block = m_entityManager.addEntity("tile");

	block->cAnimation = std::make_shared<CAnimation>(m_game->assets().getAnimation("Block"), true);
	block->cTransform = std::make_shared<CTransform>(Vec2(224, 480));
	block->cBBox = std::make_shared<CBBox>((m_game->assets().getAnimation("Block").getSize()));

	/*block->addComponent<CAnimation>(m_game->assets().getAnimation("Block"), true);
	block->addComponent<CTransform>(Vec2(224,480));
	block->addComponent<CBBox>(m_game->assets().getAnimation("Block").getSize());*/

	auto question = m_entityManager.addEntity("tile");

	question->cAnimation = std::make_shared<CAnimation>(m_game->assets().getAnimation("Question"), true);
	question->cTransform = std::make_shared<CTransform>(Vec2(352, 480));

	//question->addComponent<CAnimation>(m_game->assets().getAnimation("Question"), true);
	//question->addComponent<CTransform>(Vec2(352, 480));

	//auto& transform2 = entity->get<CTransform>();
}

ScenePlay::ScenePlay(GameEngine* gameEngine, const std::string& levelPath)
	:Scene(gameEngine), m_levelPath(levelPath)
{
	init(m_levelPath);
}

Vec2 ScenePlay::gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> e)
{
	return Vec2(0,0);
}

void ScenePlay::spawnPlayer()
{
	auto e = m_entityManager.addEntity("player");

	e->cAnimation = std::make_shared<CAnimation>(m_game->assets().getAnimation("WizardStand"), true);
	e->cTransform = std::make_shared<CTransform>(Vec2(224, 352));
	e->cBBox = std::make_shared<CBBox>(Vec2(48, 48));
	e->cGravity = std::make_shared<CGravity>(0.1f);
	e->cInput = std::make_shared<CInput>();

	m_player = e;
	
	//m_player->addComponent<CAnimation>(m_game->assets().getAnimation("WizardStand"), true);
	//m_player->addComponent<CTransform>(Vec2(224, 352));
	//m_player->addComponent<CBBox>(Vec2(48, 48));
	//m_player->addComponent<CGravity>(0.1);
	//auto player = m_entityManager.addEntity("player");
	//player->add<CAnimation>(m_game.assets().getAnimation("Stand"), true);
	//player->add<CTransform>(Vec2(224, 352));
	//player->add<CBoundingBox>(Vec2(48, 48));
	//player->add<CState>("stand");
	//player->add<CInput>();

}

void ScenePlay::spawnBullet(std::shared_ptr<Entity> entity)
{
}

void ScenePlay::update()
{
	m_entityManager.update();
	sMovement();
	sLifespan();
	sCollision();
	sAnimation();
	sGUI();
	sRender();
}

void ScenePlay::sMovement()
{
	/*Vec2 playerVelocity(0, m_player->getComponent<CTransform>().velocity.y);

	if (m_player->getComponent<CInput>().up)
	{
		playerVelocity.y = -3;
	}

	m_player->getComponent<CTransform>().velocity = playerVelocity;

	for (auto e : m_entityManager.getEntities())
	{
		if (e->hasComponent<CGravity>())
		{
			e->getComponent<CTransform>().velocity.y += e->getComponent<CGravity>().gravity;
		}
		
		e->getComponent<CTransform>().pos += e->getComponent<CTransform>().velocity;
	}*/
}

void ScenePlay::sLifespan()
{
}

void ScenePlay::sCollision()
{
}

void ScenePlay::sAnimation()
{
	/*if (m_player->getComponent<CState>().state == "air")
	{
		m_player->addComponent<CAnimation>(m_game->assets().getAnimation("Air"));
	}*/
	
	/*
	if (player()->get<CState>().state == "run")
	{
		player()->add<CAnimation>(m_game.assets().getAnimation("Run"), true);
	}*/
}

void ScenePlay::sGUI()
{
	//ImGui::Begin("Scene Properties");
	/*if (ImGui::BeginTabBar("MyTabBar"))
	{
		if (ImGui::BeginTabItem("Actions"))
		{
			for (const auto& [key, name] : getActionMap())
			{
				std::string ss = "START##" + name;
				std::string se = "END##" + name;

				if (ImGui::Button(ss.c_str()))
				{
					doAction(Action(name, "START"));
				}
				ImGui::SameLine();
				if (ImGui::Button(se.c_str()))
				{
					doAction(Action((name, "END")));
				}
				ImGui::SameLine();
				ImGui::Text("%s", name.c_str());
			}
			ImGui::EndTabItem();
		}*/

		/*if (ImGui::BeginTabItem("Assets"))
		{
			if(ImGui::CollapsingHeader("Animations", ImGuiTreeNodeFlags))
		}*/
	
}

void ScenePlay::sRender()
{
	/*if (!m_paused)
	{
		m_game.window().
	}
}*/
}

void ScenePlay::sDoAction(const Action& action)
{
	if (action.type() == "START")
	{
		if (action.name() == "TOGGLE_TEXTURE")
		{
			m_drawTextures = !m_drawTextures;
		}
		else if (action.name() == "TOGGLE_COLLISION")
		{
			m_drawCollision = !m_drawCollision;
		}
		else if (action.name() == "TOGGLE_GRID")
		{
			m_drawGrid = !m_drawGrid;
		}
		else if (action.name() == "PAUSE")
		{
			//setPaused(!m_paused);
		}
		else if (action.name() == "QUIT")
		{
			//onEnd();
		}
		else if (action.name() == "RIGHT")
		{
			//player()->get<CInput>().right = true;
		}
		else if (action.name() == "UP")
		{
			//m_player->getComponent<CInput>().up = true;
		}
	}
	else if (action.type() == "END")
	{
		if (action.name() == "RIGHT")
		{
			//player()->get<CInput>().right = false;
		}
		else if (action.name() == "UP")
		{
			//m_player->getComponent<CInput>().up = false;
		}
	}
	
}

void ScenePlay::onEnd()
{
}
