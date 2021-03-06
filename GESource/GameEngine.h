//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_GAMEENGINE_H
#define GAMEENGINE2D_GAMEENGINE_H
#include "CommonHeaders.h"
#include "Scene.h"
#include "Assets.h"
#include <memory>

using SceneMap = std::map<std::string, std::shared_ptr<Scene>>;

//struct GEGameConfig   {int W,H,FL,FS;};

class GameEngine
{
private:
    //GEGameConfig        m_gameConfig;
    SceneMap            m_sceneMap;
    sf::RenderWindow    m_window;
    Assets              m_assets;
    std::string         m_currentScene;
    bool                m_running=true;
    size_t              m_simulationSpeed = 1;

    void init(const std::string & path);
    std::shared_ptr<Scene> currentScene();
    void update();
    void sUserInput();
public:
    explicit GameEngine(const std::string & path);

    void changeScene(const std::string & sceneName,std::shared_ptr<Scene> scene, bool endCurrentScene = false);
    const Assets & getAssets() const;
    sf::RenderWindow & window();
    void run(); // game main loop
    void quit();
    bool isRunning() const;

};


#endif //GAMEENGINE2D_GAMEENGINE_H
