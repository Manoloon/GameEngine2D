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

void Scene::registerAction(Action)
{

}

void Scene::setPaused(bool paused)
{
    m_paused = paused;
}

size_t Scene::getWidth() const
{
    return m_game->window().getSize().x;
}

size_t Scene::getcurrentFrame() const
{
    return m_currentFrame;
}

size_t Scene::getHeight() const
{
    return m_game->window().getSize().y;
}
