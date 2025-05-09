#pragma once

#include "EntityManager.h"
#include "Scene.h"
#include "GameEngine.h"
#include "Action.h"

class ScenePlay: public Scene
{
	struct PlayerConfig
	{
		float X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
		std::string WEAPON;
	};

protected:

	std::shared_ptr<Entity> m_player;
	std::string m_levelPath;
	PlayerConfig m_playerConfig;
	bool m_drawTextures = true;
	bool m_drawCollision = false;
	bool m_drawGrid = false;
	const Vec2 m_gridSize = { 64,64 };
	sf::Text m_gridText;

	void init(const std::string& levelPath);
	void loadLevel(const std::string& filename);

public:
	ScenePlay(GameEngine* gameEngine, const std::string& levelPath);
		
	Vec2 gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> e);
	void spawnPlayer();
	void spawnBullet(std::shared_ptr<Entity> entity);
	void update();
	void sMovement();
	void sLifespan();
	void sCollision();
	void sAnimation();
	void sGUI();
	void sRender();
	void sDoAction(const Action& action);
	void onEnd();
};

