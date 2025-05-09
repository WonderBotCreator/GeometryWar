#include "Scene.h"

void Scene::onEnd()
{
}

void Scene::setPaused(bool paused)
{
}

Scene::Scene()
{
}

Scene::Scene(GameEngine* gameEngine)
{
}

void Scene::doAction(const Action& action)
{
}

void Scene::simulate(const size_t frames)
{
}

void Scene::registerAction(int inputKey, const std::string& actionName)
{
}

bool Scene::hasEnded() const
{
	return false;
}

const ActionMap& Scene::getActionMap() const
{
	// TODO: insert return statement here
	return m_actionMap;
}

void Scene::drawLine(const Vec2& p1, const Vec2& p2)
{
}
