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
    // TODO : falta la config de Font
    std::ifstream stream(config);
    std::string first;
    while (stream >> first)
    {
        if(first == "Window")
        {
            stream >> m_gameConfig.W >> m_gameConfig.H >> m_gameConfig.FL >> m_gameConfig.FS;
        }
        else if(first == "Font")
        {
            stream >> m_fontConfig.F >> m_fontConfig.S
                   >> m_fontConfig.R >> m_fontConfig.G >> m_fontConfig.B;
        }
        else if (first =="Player")
        {
            stream >> m_playerConfig.SR >> m_playerConfig.CR >> m_playerConfig.S
                   >> m_playerConfig.FR >> m_playerConfig.FG >> m_playerConfig.FB
                   >> m_playerConfig.OR >> m_playerConfig.OG >> m_playerConfig.OB
                   >> m_playerConfig.OT >> m_playerConfig.V;
        }
        else if (first == "Enemy")
        {
            stream >> m_enemyConfig.SR >> m_enemyConfig.CR >> m_enemyConfig.SMIN
                   >> m_enemyConfig.SMAX >> m_enemyConfig.OR >> m_enemyConfig.OG
                   >> m_enemyConfig.OB >> m_enemyConfig.OT >> m_enemyConfig.VMIN
                   >> m_enemyConfig.VMAX >> m_enemyConfig.L >> m_enemyConfig.SP;
        }
        else if (first == "Bullet")
        {
            stream >> m_bulletConfig.SR >> m_bulletConfig.CR >> m_bulletConfig.S
                   >> m_bulletConfig.FR >> m_bulletConfig.FG >> m_bulletConfig.FB
                   >> m_bulletConfig.OR >> m_bulletConfig.OG >> m_bulletConfig.OB
                   >> m_bulletConfig.OT >> m_bulletConfig.V >> m_bulletConfig.L;
        }
    }

    //sf::Text text("Score",m_font,24);
    if(!m_font.loadFromFile(m_fontConfig.F))
    {
        std::cerr << "FONT COULDNT LOAD\n";
        exit(-1);
    }
    m_text.setFont(m_font);
    m_text.setCharacterSize(m_fontConfig.S);
    m_text.setFillColor(sf::Color(m_fontConfig.R,m_fontConfig.G,m_fontConfig.B));
    m_text.setString("Score");
    m_text.setPosition(0,m_window.getSize().y -(float)m_text.getCharacterSize());
    m_window.create(sf::VideoMode(m_gameConfig.W,m_gameConfig.H),"Game Engine 2D");
    m_window.setFramerateLimit(m_gameConfig.FL);
    spawnPlayer();
}

void Game::setPaused(bool paused)
{
    m_paused =paused;
}

void Game::run()
{
    while (m_running)
    {
        m_entities.Update();

        if(!m_paused)
        {
            sEnemySpawner();
            sMovement();
            sCollision();
            sLifespan();
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
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(0, 0), 0.0f);
    // the entity shape will have a radius 32, 8 sides, dark grey fill , and red outline of thickness 4
    entity->cShape = std::make_shared<CShape>(m_playerConfig.SR, m_playerConfig.V, sf::Color(m_playerConfig.FR,m_playerConfig.FG,m_playerConfig.FB),
                                              sf::Color(m_playerConfig.OR,m_playerConfig.OG,m_playerConfig.OB), m_playerConfig.OT);
    // add an input component to the player
    entity->cInput = std::make_shared<CInput>();
    entity->cCollision = std::make_shared<CCollision>(m_playerConfig.CR);
    // this goes against entityManager paradigm , but the player is a pretty heavy used class
    m_player = entity;
}

void Game::spawnEnemy()
{
    //TODO : make sure the enemy spawn properly with the enemyConfig
    // the enemy must be spawned completely inside bounds of windows.
    //spawn location random (inside bounds and not near the player.)
    // speed random Smin,Smax
    // vertice random (VMin,vMAx)
    // Color fill debe ser random.

    auto entity = m_entities.addEntity("enemy");
    // gives this entity a transform so it spawns at (200,200) with velocity (1,1) and angle 0
    //TODO : definir esta data en random.
    auto SpawnLocX = 1+(std::rand() %(1+m_window.getSize().x - 1));
    auto SpawnLocY = 1+(std::rand() %(1+m_window.getSize().y - 1));
    auto EVel = m_enemyConfig.SMIN +(std::rand() % (1+m_enemyConfig.VMAX - m_enemyConfig.VMIN));
    entity->cTransform = std::make_shared<CTransform>(Vec2(SpawnLocX,SpawnLocY), Vec2(m_enemyConfig.VMIN,m_enemyConfig.VMIN),1.0f);
    // the entity shape will have a radius 32, 8 sides, dark grey fill , and red outline of thickness 4
    auto CO =  sf::Color(m_enemyConfig.OR,m_enemyConfig.OG,m_enemyConfig.OB);
    entity->cShape = std::make_shared<CShape>(m_enemyConfig.SR,8,sf::Color(10,255,10),
                                             CO,m_enemyConfig.OT);
    entity->cCollision=std::make_shared<CCollision>(m_enemyConfig.CR);
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
       smallEnemy->cTransform = std::make_shared<CTransform>(entity->cTransform->pos,entity->cTransform->velocity,entity->cTransform->angle);
       // set each small enemy to the same color as the original, half the size
       smallEnemy->cShape = std::make_shared<CShape>(8,vertices,entity->cShape->shape.getFillColor(),
                                                      entity->cShape->shape.getOutlineColor(),entity->cShape->shape.getOutlineThickness());
       smallEnemy->cCollision = std::make_shared<CCollision>(8);
       // the small enemies are worth double of the original score.
       smallEnemy->cScore = std::make_shared<CScore>(entity->cScore->score*2);
       smallEnemy->cLifespan=std::make_shared<CLifespan>(m_enemyConfig.L);
    }
}

void Game::spawnBullet(ptr<Entity> entity, const Vec2 &mousePos)
{
    //TODO: implement the spawning of a bullet which travels toward target
    // bullet speed is given as a scalar speed
    // you must set the velocity by using formula in notes.
    auto bullet = m_entities.addEntity("bullet");
    const auto CF = sf::Color(m_bulletConfig.FR,m_bulletConfig.FG,m_bulletConfig.FB);
    const auto CO = sf::Color(sf::Color(m_bulletConfig.OR,m_bulletConfig.OG,m_bulletConfig.OB));
    bullet->cShape = std::make_shared<CShape>(m_bulletConfig.SR,m_bulletConfig.V,CF,CO,m_bulletConfig.OT);
    bullet->cLifespan=std::make_shared<CLifespan>(m_bulletConfig.L);
    float newAngle = entity->cTransform->pos.getAngle(mousePos-entity->cTransform->pos);
    bullet->cTransform = std::make_shared<CTransform>(Vec2(entity->cTransform->pos.x,entity->cTransform->pos.y),bullet->cTransform->pos.getVelocity(3,newAngle),newAngle);
    bullet->cCollision = std::make_shared<CCollision>(m_bulletConfig.CR);
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
                playerVelocity.y -= m_playerConfig.S;
            }
            if(m_player->cInput->down)
            {
                playerVelocity.y += m_playerConfig.S;
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
        uint8_t alpha = 100;
        sf::Color newColor(color.r,color.g,color.b,alpha);
        e->cShape->shape.setFillColor(newColor);
        /**
        while(alpha >0)
        {
            alpha -=0.01;
        }
        e->destroy();
         */
    }

    //  if its has lifespan and its time is up - destroy entity.
}

void Game::sCollision()
{
    // be sure to use the collision radius, NOT shape radius.
    for(auto p: m_entities.getEntities("player"))
    {
        for (auto e : m_entities.getEntities("enemy"))
        {
            float dist = p->cTransform->pos.distSquare(e->cTransform->pos);
           if(dist<(p->cCollision->radius + e->cCollision->radius))
            {
               p->destroy();
               e->destroy();
               spawnPlayer();
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
                SpawnSmallEnemies(e);
                e->destroy();
                b->destroy();
            }
        }
    }

    for(auto e :m_entities.getEntities())
    {
        if(e->cTransform->pos.x < 0 ||  e->cTransform->pos.x > m_window.getSize().x)
        {
            e->cTransform->velocity.x *=-1;
        }
        else if (e->cTransform->pos.y < 0 ||  e->cTransform->pos.y > m_window.getSize().y)
        {
            e->cTransform->velocity.y *=-1;
        }
    }
}

void Game::sEnemySpawner()
{
    // use m_currentFrame - m_lastEnemySpawnTime -> to determine
    // how long it has been since the last enemy spawned
    int spawnFrequency = 200; // +(std::rand() % (1+700-100));
    if(m_currentFrame >spawnFrequency)
    {
        m_currentFrame -= m_lastEnemySpawnTime;
        spawnEnemy();
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
    m_window.draw(m_text);
    m_window.display();
}

void Game::sUserInput()
{
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
                    setPaused(!m_paused);
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
        if(!m_paused)
        {
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
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
}
