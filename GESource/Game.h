//
// Created by Manoloon on 18/12/2021.
//

#ifndef GAMEENGINE2D_GAME_H
#define GAMEENGINE2D_GAME_H

#include "CommonHeaders.h"
#include "Entity.h"
#include "EntityManager.h"
/**
 * shape radius :           SR
 * Collision radius :       CR
 * speed :                  S
 * Spawn Interval :         SP
 * Fill Color :             FR,FG,FB
 * Outline Color :          OR,OG,OB
 * Outline Thickness :      OT
 * Shape Vertices :         V
 * Lifespan :               L
 *
 * Width :                  W  Height :                 H
 * Frame limit :            FL FullScreen:              FS
 */
struct GameConfig   {int W,H,FL,FS;};
struct FontConfig {std::string F; int S,R,G,B;};
struct PlayerConfig {int SR,CR; float S; int FR,FG,FB,OR,OG,OB,OT,V; };
struct EnemyConfig  {int SR,CR;float SMIN,SMAX; int OR,OG,OB,OT,VMIN,VMAX,L,SP;};
struct BulletConfig {int SR,CR; float S; int FR,FG,FB,OR,OG,OB,OT,V,L;};

class Game
{
    sf::RenderWindow m_window;
    EntityManager   m_entities;
    sf::Font        m_font;
    sf::Text        m_text;
    GameConfig      m_gameConfig;
    FontConfig      m_fontConfig;
    PlayerConfig    m_playerConfig;
    EnemyConfig     m_enemyConfig;
    BulletConfig    m_bulletConfig;
    int             m_score=0;
    int             m_currentFrame=0;
    int             m_lastEnemySpawnTime =0;
    bool            m_paused= false;
    bool            m_running=true;
    bool            m_debugCollisions= false;

    ptr<Entity> m_player;

    void init(const std::string & config);
    void setPaused(bool paused);

    // Systems
    void sMovement(float DeltaTime);
    void sUserInput();
    void sLifespan(float DeltaTime);
    void sRender();
    void sEnemySpawner();
    void sCollision();

    void spawnPlayer();
    void spawnEnemy();
    void SpawnSmallEnemies(ptr<Entity> entity);
    void spawnBullet(ptr<Entity> entity, const Vec2 & mousePos);
    void spawnSpecialWeapon(ptr<Entity> entity);

public:
    explicit Game(const std::string & config);
    void run();
};


#endif //GAMEENGINE2D_GAME_H
