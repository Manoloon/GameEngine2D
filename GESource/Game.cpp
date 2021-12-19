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
    int vertices = entity->cShape->shape.getPointCount();
    for(int i=0;i<vertices;i++)
    {
        auto smallEnemy = m_entities.addEntity("small");
        // the small enemies are worth double of the original score.
        smallEnemy->cScore = std::make_shared<CScore>(entity->cScore->score*2);
        // set each small enemy to the same color as the original, half the size
        smallEnemy->cShape = std::make_shared<CShape>(entity->cShape->shape.getFillColor());
        smallEnemy->cShape = std::make_shared<CShape>(entity->cShape->shape.getScale()/2);
    }
}

void Game::spawnBullet(ptr<Entity> entity, const Vec2 &mousePos)
{
    //TODO: implement the spawning of a bullet which travels toward target
    // bullet speed is given as a scalar speed
    // you must set the velocity by using formula in notes.
}

void Game::spawnSpecialWeapon(ptr<Entity> entity)
{
    //TODO: implement a special weapon.
}

void Game::sMovement()
{
    // TODO : implement all entity movement
    for(auto e : m_entities.getEntities())
    {

    }
    Vec2 playerVelocity;
    if(m_player->cInput->left)
    {
        playerVelocity.x -= m_playerConfig.S;
    }
    if(m_player->cInput->right)
    {
        playerVelocity.x += m_playerConfig.S;
    }
    if(m_player->cInput->up)
    {
        playerVelocity.y += m_playerConfig.S;
    }
    if(m_player->cInput->down)
    {
        playerVelocity.y -= m_playerConfig.S;
    }
    // you should read the m-player->cinput comp to determine if the player is moving
    m_player->cTransform->pos += m_player->cTransform->velocity;
    //this is just a sample.
    m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
    m_player->cTransform->pos.y += m_player->cTransform->velocity.y;
}

void Game::sLifespan()
{
    //TODO : implement all lifespan funct.
    for(auto e : m_entities.getEntities())
    {
        if(!e->cLifespan){continue;}
    }
    // if entity has no lifespan comp , skip.
    // if entity has > 0 current lifespan , substract 1
    // scale its alpha channel properly
    //  if its has lifespan and its time is up - destroy entity.
}
