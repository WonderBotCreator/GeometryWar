#pragma once

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "EntityManager.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <cmath>


struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

class Assignment2
{
	sf::RenderWindow m_window;
	EntityManager m_entities;
	sf::Font m_font;
	sf::Text m_text;
	PlayerConfig m_playerConfig;
	EnemyConfig m_enemyConfig;
	BulletConfig m_bulletConfig;

	bool enableRender;
	bool enableUserInput;
	bool enableSpawnEnemy;
	bool enableCollision;

	int m_spawnEnemyNumber = 1;

	bool m_running;
	bool isMouseAlreadyPressed = false;

	sf::Clock m_deltaClock;

	sf::Clock clock2;

	int target_time = 5;

	int m_score = 0;
	int m_currentFrame = 0;

	int mousePosX = 0.f;
	int mousePosY = 0.f;

	std::shared_ptr<Entity> m_player;

	void init();

	void spawnPlayer();

	void sEnemySpawner();
	void sBulletSpawner();
	void sMovement();
	void sCollision();
	void sUserInput();
	void sGUI();
	void sRender();

public:
	Assignment2();
	void run();
};

