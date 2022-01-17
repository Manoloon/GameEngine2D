//
// Created by Manoloon on 09/01/2022.
//

#include "Scene.h"
#include "GameEngine.h"

Scene::Scene(GameEngine *gameEngine):m_game(gameEngine){}

void Scene::simulate(int)
{
    // TODO : simulate differents behavior automatic.
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

void Scene::doAction(const Action & action)
{

}

void Scene::sRender()
{
    m_game->window().clear();
    // all of this are only for the player.
    // set the position of the shape based on the entity transform->pos.
    for(auto e : m_entityManager.getEntities())
    {
        e->getComponent<CAnimation>();
        e->cTransform->angle +=1.0f;
        m_game->window().draw();
    }
    m_game->window().display();
}
