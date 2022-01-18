//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_SCENE_MENU_H
#define GAMEENGINE2D_SCENE_MENU_H
#include "GameEngine.h"
#include "Scene.h"

class Scene_Menu : public Scene
{
public:
    Scene_Menu() = default;
    explicit Scene_Menu (GameEngine * gameEngine);
    void sDoAction(const Action& action) override;
    void sRender() override;
    void update() override;
private:
    std::string                 m_title;
    std::vector<std::string>    m_menuString{};
    std::vector<std::string>    m_levelPaths{};
    int                         m_selectedMenuIndex=0;
    sf::Text                    m_menuText;
    void init();
    void onEnd();
};

#endif //GAMEENGINE2D_SCENE_MENU_H
