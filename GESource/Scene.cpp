//
// Created by Manoloon on 09/01/2022.
//

#include "Scene.h"

Scene::Scene(GameEngine *gameEngine)
{

}

void Scene::simulate(int)
{

}

void Scene::doAction(Action)
{

}

void Scene::registerAction(int inputKey ,std::string actionName)
{
    m_actionMap[inputKey] = actionName;
}

void Scene::setPaused(bool paused)
{
    m_paused = paused;
}

size_t Scene::getWidth() const
{
    return m_game->window().getSize().x;
}

size_t Scene::getCurrentFrame() const
{
    return m_currentFrame;
}

size_t Scene::getHeight() const
{
    return m_game->window().getSize().y;
}

std::map<int, std::string> Scene::getActionMap() const
{
    return m_actionMap;
}
