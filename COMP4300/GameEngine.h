#pragma once

#include "Scene.h"
#include "Assets.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SceneMenu.h"


typedef std::map<std::string, std::shared_ptr<Scene>> SceneMap;

class GameEngine
{
	void mainLoop();

protected:
	sf::RenderWindow m_window;
	Assets m_assets;
	std::string m_currentScene;
	SceneMap m_sceneMap;
	size_t m_simulationSpeed = 1;
	sf::Clock m_deltaClock;
	bool m_running = true;

	void init(const std::string& path);
	void update();

	void sUserInput();

	std::shared_ptr<Scene> currentScene();

public:
	GameEngine(const std::string& path);
	void changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene = false);
	void quit();
	void run();

	sf::RenderWindow& window();
	const Assets& assets() const;

	bool isRunning();
};

