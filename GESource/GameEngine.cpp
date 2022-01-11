//
// Created by Manoloon on 09/01/2022.
//

#include "GameEngine.h"

GameEngine::GameEngine(const std::string &path)
{

}

void GameEngine::init(const std::string &path)
{

}

std::shared_ptr<Scene> GameEngine::currentScene()
{
    return std::shared_ptr<Scene>();
}

void GameEngine::update()
{

}

void GameEngine::sUserInput()
{

}

void GameEngine::quit()
{

}

void GameEngine::changeScene(const std::string &sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene)
{

}

Assets &GameEngine::getAssets() const
{
    return <#initializer#>;
}

sf::RenderWindow &GameEngine::window()
{
    return m_window;
}

void GameEngine::run()
{

}

bool GameEngine::isRunning()
{
    return m_running;
}
