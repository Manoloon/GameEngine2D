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
        m_entities.Update();

        if(!m_paused)
        {
            sEnemySpawner();
            sMovement();
            sCollision();
            // increment current frame
            m_currentFrame++;
        }
        sUserInput();
        sRender();
    }
}

void Game::spawnPlayer()
{
    //TODO : finish adding all props of the player with the correct values from the config.

    // create player
    auto entity = m_entities.addEntity("player");

    // gives this entity a transform so it spawns at (200,200) with velocity (1,1) and angle 0
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f,200.0f),Vec2(0,0),0.0f);
    // the entity shape will have a radius 32, 8 sides, dark grey fill , and red outline of thickness 4
    entity->cShape = std::make_shared<CShape>(32.0f,8,sf::Color(10,10,10), sf::Color(255,0,0),4.0f);
    // add an input component to the player
    entity->cInput = std::make_shared<CInput>();
    entity->cCollision = std::make_shared<CCollision>(32.0f);
    // this goes against entityManager paradigm , but the player is a pretty heavy used class
    m_player = entity;
}

void Game::spawnEnemy()
{
    //TODO : make sure the enemy spawn properly with the enemyConfig
    // the enemy must be spawned completely inside bounds of windows.
    auto entity = m_entities.addEntity("enemy");
    // gives this entity a transform so it spawns at (200,200) with velocity (1,1) and angle 0
    //TODO : definir esta data en random.
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f,400.0f),Vec2(1,1),1.0f);
    // the entity shape will have a radius 32, 8 sides, dark grey fill , and red outline of thickness 4
    entity->cShape = std::make_shared<CShape>(16.0f,8,sf::Color(10,255,10), sf::Color(0,255,0),1.0f);
    entity->cCollision=std::make_shared<CCollision>(16);
    entity->cScore = std::make_shared<CScore>(10);
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
       smallEnemy->cLifespan=std::make_shared<CLifespan>(10);
       // set each small enemy to the same color as the original, half the size
       smallEnemy->cShape = std::make_shared<CShape>(8,vertices,entity->cShape->shape.getFillColor(),
                                                     entity->cShape->shape.getOutlineColor(),entity->cShape->shape.getOutlineThickness());
       smallEnemy->cCollision = std::make_shared<CCollision>(8);
    }
}

void Game::spawnBullet(ptr<Entity> entity, const Vec2 &mousePos)
{
    //TODO: implement the spawning of a bullet which travels toward target
    // bullet speed is given as a scalar speed
    // you must set the velocity by using formula in notes.
    auto bullet = m_entities.addEntity("bullet");
    bullet->cShape = std::make_shared<CShape>(8,3,sf::Color::Blue,sf::Color::Cyan,1);
    bullet->cLifespan=std::make_shared<CLifespan>(10);
    float newAngle = entity->cTransform->pos.getAngle(mousePos-entity->cTransform->pos);
    bullet->cTransform = std::make_shared<CTransform>(Vec2(entity->cTransform->pos.x,entity->cTransform->pos.y),bullet->cTransform->pos.getVelocity(3,newAngle),newAngle);
    std::cout << "b X" << bullet->cTransform->pos.x << " " << "b Y" << bullet->cTransform->pos.y << std::endl;
    bullet->cCollision = std::make_shared<CCollision>(16);
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
        if(e->GetTag()=="player")
        {
            Vec2 playerVelocity{};
            // TODO: cuando implemente el config.txt -> volver a usar el playerconfig.
            if(m_player->cInput->left)
            {
                playerVelocity.x -= 1;//m_playerConfig.S;
            }
            if(m_player->cInput->right)
            {
                playerVelocity.x += 1;//m_playerConfig.S;
            }
            if(m_player->cInput->up)
            {
                playerVelocity.y -= 1;// m_playerConfig.S;
            }
            if(m_player->cInput->down)
            {
                playerVelocity.y += 1;//m_playerConfig.S;
            }
            m_player->cTransform->velocity = playerVelocity;
            // you should read the m-player->cinput comp to determine if the player is moving
            m_player->cTransform->pos += m_player->cTransform->velocity;
        }
        else
        {
            // TODO : esto es hasta que implementemos el config.txt
            e->cTransform->pos += e->cTransform->velocity;
        }
    }
}

void Game::sLifespan()
{
    //TODO : implement all lifespan funct.
    // if entity has no lifespan comp , skip.
    // if entity has > 0 current lifespan , substract 1
    // scale its alpha channel properly
    for(auto e : m_entities.getEntities())
    {
        if(!e->cLifespan){continue;}
        auto color = e->cShape->shape.getFillColor();
        sf::Uint8 alpha = 100;
        sf::Color newColor(color.r,color.g,color.b,alpha);
        e->cShape->shape.setFillColor(newColor);
    }

    //  if its has lifespan and its time is up - destroy entity.
}

void Game::sCollision()
{
    //TODO: implement all proper collisions btw entities
    // be sure to use the collision radius, NOT shape radius.
    for(auto p: m_entities.getEntities("player"))
    {
        for (auto e : m_entities.getEntities("enemy"))
        {
            float dist = p->cTransform->pos.distSquare(e->cTransform->pos);
           if(dist<(p->cCollision->radius + e->cCollision->radius))
            {

               // p->destroy();
               //SpawnSmallEnemies(e);
               e->destroy();
            }
        }
    }
    for(auto b: m_entities.getEntities("bullet"))
    {
        for (auto e : m_entities.getEntities("enemy"))
        {
            float dist = b->cTransform->pos.dist(e->cTransform->pos);
            if(dist<(b->cCollision->radius + e->cCollision->radius))
            {

                // p->destroy();
                //SpawnSmallEnemies(e);
                e->destroy();
                b->destroy();
            }
        }
    }
    //TODO: falta check limites de la pantalla , que nadie salga de ella.
}

void Game::sEnemySpawner()
{
 // TODO: code which implements enemy spawning should go here.
    // use m_currentFrame - m_lastEnemySpawnTime -> to determine
    // how long it has been since the last enemy spawned
    int spawnFrequency = 200; // +(std::rand() % (1+700-100));
    if(m_currentFrame >spawnFrequency)
    {
        m_currentFrame -= m_lastEnemySpawnTime;
        std::cout << "SPAWN" << std::endl;
        spawnEnemy();
    }
    else
    {
       // std::cout << m_currentFrame << std::endl;
    }
}

void Game::sRender()
{
    m_window.clear();
    // all of this are only for the player.
    // set the position of the shape based on the entity transform->pos.
    for(auto e : m_entities.getEntities())
    {
        e->cShape->shape.setPosition(e->cTransform->pos.x,e->cTransform->pos.y);
        e->cTransform->angle +=1.0f;
        e->cShape->shape.setRotation(e->cTransform->angle);
       // if(m_debugCollisions)
        //{
          //  m_window.draw(e->cCollision->shape);
        //}
        m_window.draw(e->cShape->shape);
    }
    m_window.display();
}

void Game::sUserInput()
{
    //TODO : handle user input here
            // note that you should only be setting the player`s input comp var here.
            // you should not implement the player movement logic here.
            // the movement system will read the vars you set in here.
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_running = false;
        }
        if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::W:
                    m_player->cInput->up = true;
                    break;
                case sf::Keyboard::S:
                    m_player->cInput->down = true;
                    break;
                case sf::Keyboard::A:
                    m_player->cInput->left = true;
                    break;
                case sf::Keyboard::D:
                    m_player->cInput->right = true;
                    break;
                    // Options
                case sf::Keyboard::P:
                    m_paused=!m_paused;
                    std::cout << "Game Paused :"<< m_paused << std::endl;
                    break;
                case sf::Keyboard::Escape:
                    m_running=false;
                    break;
                case sf::Keyboard::O:
                    m_debugCollisions =!m_debugCollisions;
                    std::cout << "Debug Collisions :"<< m_debugCollisions << std::endl;
                    break;
            }
        }
        if(event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
                m_player->cInput->up = false;
            break;
            case sf::Keyboard::S:
                m_player->cInput->down = false;
            break;
            case sf::Keyboard::A:
                m_player->cInput->left = false;
            break;
            case sf::Keyboard::D:
                m_player->cInput->right = false;
            break;
            }
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button==sf::Mouse::Left)
            {
                // TODO: spawn bullet
                sf::Vector2i position = sf::Mouse::getPosition();
                spawnBullet(m_player,{static_cast<float>(position.x),static_cast<float>(position.y)});
            }
            if(event.mouseButton.button == sf::Mouse::Right)
            {
                // TODO : special weapon.
            }
        }
    }
}
