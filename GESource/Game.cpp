//
// Created by Manoloon on 18/12/2021.
//

#include "Game.h"

Game::Game(const std::string &config)
{
    init(config);
}

void Game::init(const std::string &config)
{
    //TODO: read the config file
    // use the premade PlayerConfig, enemyConfig and BulletConfig vars
    // std::ifstream fin(path);
    // fin >> m_playerConfig.SR >> m_playerConfig.CR >> m_playerConfig.S;

    m_window.create(sf::VideoMode(1280,720),"Game Engine 2D");
    m_window.setFramerateLimit(60);
    spawnPlayer();
}

void Game::setPaused(bool paused)
{
    m_paused =paused;
}

void Game::run()
{
    //TODO : add pause functionality
    // some systems should run while paused
    // some dont.
    while (m_running)
    {
        m_entities.update();

        if(!m_paused)
        {
            sMovement();
            sCollision();
            sUserInput();

            // increment current frame
            m_currentFrame++;
        }
        sRender();
    }
}

void Game::spawnPlayer()
{
    //TODO : finish adding all props of the player with the correct values from the config.

    // create player
    auto entity = m_entities.addEntity("player");

    // gives this entity a transform so it spawns at (200,200) with velocity (1,1) and angle 0
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f,200.0f),Vec2(1,1),0.0f);
    // the entity shape will have a radius 32, 8 sides, dark grey fill , and red outline of thickness 4
    entity->cShape = std::make_shared<CShape>(32.0f,8,sf::Color(10,10,10), sf::Color(255,0,0),4.0f);
    // add an input component to the player
    entity->cInput = std::make_shared<CInput>();
    // this goes against entityManager paradigm , but the player is a pretty heavy used class
    m_player = entity;
}

void Game::spawnEnemy()
{
    //TODO : make sure the enemy spawn properly with the enemyConfig
    // the enemy must be spawned completely inside bounds of windows.

    // record when the most recent enemy was spawned
    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::SpawnSmallEnemies(ptr<Entity> entity)
{
    //TODO : spawn small enemies at the location of the input enemy e
    // spawn a number of small enemies equal to the vertices of the original enemy
    // set each small enemy to the same color as the original, half the size
    // the small enemies are worth double of the original score.
}
