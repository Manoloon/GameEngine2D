//
// Created by Manoloon on 09/01/2022.
//

#include "GameEngine.h"
#include "Assets.h"
#include "Scene_Play.h"
#include "Scene_Menu.h"

GameEngine::GameEngine(const std::string &path)
{
    init(path);
}

void GameEngine::init(const std::string &path)
{
    m_assets.LoadFromFile(path);
    m_window.create(sf::VideoMode(1280,760),"Mario 20");
    m_window.setFramerateLimit(60);
    changeScene("MENU",std::make_shared<Scene_Menu>(this));
}

std::shared_ptr<Scene> GameEngine::currentScene()
{
    return m_sceneMap[m_currentScene];
}

void GameEngine::update()
{
    if(currentScene())
    {
        currentScene()->update();
    }
  window().display();
}

void GameEngine::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) { quit(); }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::X) {
                std::cout << "Screenshot saved to" << "test.png" << std::endl;
                sf::Texture texture;
                texture.create(m_window.getSize().x, m_window.getSize().y);
                texture.update(m_window);
                if (texture.copyToImage().saveToFile("test.png")) {
                    std::cout << "Screenshot saved to" << "test.png" << std::endl;
                }
            }
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            // if current scene doesnt have action associated with key
            if (currentScene()->getActionMap().find(event.key.code) ==
                currentScene()->getActionMap().end()) { continue; }

            const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";

            currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), actionType));
        }
    }
}

void GameEngine::quit()
{
    m_running = false;
}

void GameEngine::changeScene(const std::string &sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene)
{
    if(scene)
    {
        m_sceneMap[sceneName] = scene;
        m_currentScene = sceneName;
    }
    if(m_sceneMap.find(sceneName)==m_sceneMap.end())
    {
        //TODO : ni idea !
        m_currentScene="";
    }
}

const Assets &GameEngine::getAssets() const
{
    return m_assets;
}

sf::RenderWindow &GameEngine::window()
{
    return m_window;
}

void GameEngine::run()
{
    while (isRunning())
    {
        update();
    }
}

bool GameEngine::isRunning() const
{
    return m_running;
}
