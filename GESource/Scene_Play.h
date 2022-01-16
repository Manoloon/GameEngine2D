//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_SCENE_PLAY_H
#define GAMEENGINE2D_SCENE_PLAY_H
#include "Scene.h"

struct PlayerConfig
        {
            float X,Y,CX,CY,SPEED,MAXSPEED,JUMP,GRAVITY;
            std::string WEAPON;
        };

class Scene_Play : public Scene
{
private:
    std::string m_levelPath;
    ptr<Entity> m_player;
    PlayerConfig  playerConfig;
    bool m_drawTextures =true;
    bool m_drawCollision = false;
    bool m_drawGrid = false;
    const Vec2 m_gridSize = {64,64};
    sf::Text m_gridText;
public:
    Scene_Play();
    void spawnPlayer();
    explicit Scene_Play(GameEngine * gameEngine, const std::string & levelPath);
    void spawnBullet(std::shared_ptr<Entity>entity);
    void init(const std::string & levelPath);
    void update() override;
// Systems()
    void sAnimation();
    void sMovement();
    void sLifespan();
    void sEnemySpawner();
    void sCollision();
    //void sRender();
    void sDoAction(const Action & action) override;
    void sDebug();
    void onEnd();
    Vec2 gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity);
    void loadLevel(const std::string & filename);

    void drawLine(const Vec2 & p1, const Vec2 & p2);
};

#endif //GAMEENGINE2D_SCENE_PLAY_H
