//
// Created by Manoloon on 09/01/2022.
//

#include "Scene_Menu.h"
#include "Scene_Play.h"
#include "CommonHeaders.h"
#include "Assets.h"
#include "GameEngine.h"
#include "Components.h"
#include "Action.h"

Scene_Menu::Scene_Menu(GameEngine *gameEngine) : Scene(gameEngine)
{
    init();
}

void Scene_Menu::init()
{
    registerAction(sf::Keyboard::W,         "UP");
    registerAction(sf::Keyboard::S,         "DOWN");
    registerAction(sf::Keyboard::D,         "PLAY");
    registerAction(sf::Keyboard::Escape,    "QUIT");

    m_title = "MENU";
    m_menuString.push_back("Level 1");
    m_menuString.push_back("Level 2");
    m_menuString.push_back("Level 3");

    m_levelPaths.push_back("Level1.txt");
    m_levelPaths.push_back("Level2.txt");
    m_levelPaths.push_back("Level3.txt");

    m_menuText.setFont(m_game->getAssets().getFont("Megaman"));
    m_menuText.setCharacterSize(64);
}

void Scene_Menu::update()
{
    m_entityManager.Update();
    sRender();

}

void Scene_Menu::sDoAction(const Action& action)
{
    if(action.getType() == "START")
    {
        if(action.getName() == "UP")
        {
            if(m_selectedMenuIndex > 0) {m_selectedMenuIndex--;}
            else{m_selectedMenuIndex = m_menuString.size()-1;}
        }
        else if(action.getName() == "DOWN")
        {
            m_selectedMenuIndex = (m_selectedMenuIndex +1 ) % m_menuString.size();
        }
        else if(action.getName() == "PLAY")
        {
            m_game->changeScene("PLAY", std::make_shared<Scene_Play>(m_game, m_levelPaths[m_selectedMenuIndex]));
        }
        else if (action.getName() == "QUIT")
        {
            onEnd();
        }
    }
}

void Scene_Menu::onEnd()
{
    m_game->quit();
}

void Scene_Menu::sRender()
{
    // TODO : aca esta la bocha.
    m_game->window().clear(sf::Color(100,100,255));
    auto startHeight = 104;
    for(auto menu : m_menuString)
    {
        m_menuText.setString(menu);
        m_menuText.setPosition(103,getHeight() - startHeight);
        startHeight +=120;
        m_game->window().draw(m_menuText);
    }
}
