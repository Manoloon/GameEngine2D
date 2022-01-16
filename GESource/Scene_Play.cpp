//
// Created by Manoloon on 09/01/2022.
//

#include "Scene_Play.h"
#include "CommonHeaders.h"
#include "Physics.h"
#include "Assets.h"
#include "GameEngine.h"
#include "Components.h"
#include "Action.h"

Scene_Play::Scene_Play(GameEngine * gameEngine, const std::string & levelPath):Scene(gameEngine), m_levelPath(levelPath)
{
    init(m_levelPath);
}

void Scene_Play::init(const std::string & levelPath)
{
    registerAction(sf::Keyboard::P,         "PAUSE");
    registerAction(sf::Keyboard::Escape,    "QUIT");
    registerAction(sf::Keyboard::T,         "TOGGLE_TEXTURE");
    registerAction(sf::Keyboard::C,         "TOGGLE_COLLISION");
    registerAction(sf::Keyboard::G,         "TOGGLE_GRID");

    registerAction(sf::Keyboard::D,         "RIGHT");

    m_gridText.setCharacterSize(12);
    m_gridText.setFont(m_game->getAssets().getFont("Arial"));

    loadLevel(levelPath);
}

Vec2 Scene_Play::gridToMidPixel(float gridX, float gridY, std::shared_ptr<Entity> entity)
{
   //TODO : this function takes in a grid (x,y) position and an entity
   //Return a VEC2 indicating where the CENTER position of the entity should be
   //you must use the entity animation size to position it correctly
   //the size of the grid width and height is stored in  m_gridSize.x and m_gridSize.y
   // the bottom left corner of the animation should align with the bottom left of the grid cell
    return Vec2(0,0);
}

void Scene_Play::loadLevel(const std::string & filename)
{
    m_entityManager = EntityManager();

    //TODO : read in the level file and add the appropriate entities
    //use the PlayerConfig struct m_playerconfig to store player properties
    //this struct is defined at the top of scene_play.h

    // NOTE : all the code below is sample code it should be remove.
    spawnPlayer();

    // some sample entities
    auto brick = m_entityManager.addEntity("tile");
    //IMPORTANT : always add CAnimation first so that gridtomidpixel can compute correctly
    brick->addComponent<CAnimation>(m_game->getAssets().getAnimation("Brick"),true);
    brick->addComponent<CTransform>(Vec2(96,480));
    // final code should look like this
    // brick->addComponent<CTransform>(gridToMidPixel(gridX,gridY,brick);
    if(brick->getComponent<CAnimation>().animation.getName() == "Brick")
    {
        std::cout << "this could be a good way of identify if a tile is a brick";
    }
    auto block = m_entityManager.addEntity("tile");
    block->addComponent<CAnimation>(m_game->getAssets().getAnimation("Block"),true);
    block->addComponent<CTransform>(Vec2(224,480));
    //add a bounding box .
    block->addComponent<CBBCollision>(m_game->getAssets().getAnimation("Block").getSize());

    auto question = m_entityManager.addEntity("tile");
    question->addComponent<CAnimation>(m_game->getAssets().getAnimation("Question"), true);
    question->addComponent<CTransform>(Vec2(352,480));
    // NOTE : IMPORTANT
    //components are now returned as references rather than pointers
    // if you do not specify a ref variable type, it will COPY the comp.
    //EXAMPLE:
    // auto & transform = entity->get<CTransform>()
}

void Scene_Play::spawnPlayer()
{
    // sample code
    m_player = m_entityManager.addEntity("player");
    m_player->addComponent<CAnimation>(m_game->getAssets().getAnimation("Stand"),true);
    m_player->addComponent<CTransform>(Vec2(224,352));
    m_player->addComponent<CBBCollision>(Vec2(48,48));

    //TODO : be sure to add remaining components to the player
}

void Scene_Play::spawnBullet(std::shared_ptr<Entity>entity)
{
    // TODO : spawn bullet at the give entity. going in the direction the entity is facing
}

void Scene_Play::update()
{
    sf::Clock m_clock;
    m_entityManager.Update();
    //TODO : implement pause funct
    if(!m_paused)
    {
        sf::Time m_deltaTime = m_clock.restart();
        sMovement();
        sLifespan();
        sCollision();
        sAnimation();
        // increment current frame
        m_currentFrame++;
        //std::cout << m_deltaTime.asSeconds() <<'\n';
        //std::cout << "Current Frame : " << m_currentFrame <<'\n';
    }
    sRender();
}

void Scene_Play::sAnimation()
{
    //TODO : complete the animation code first
    //TODO : set the animation of the player based on its CState comp
    //TODO : for each entity with an animation , call entity->getComponent<CAnimation>().animation.update()
    // if the anim is not repeated, and it has ended , destroy the entity.
}

void Scene_Play::sDoAction(const Action & action)
{
    if(action.getType() == "START")
    {
        if(action.getName() == "TOGGLE_TEXTURE")       {m_drawTextures = !m_drawTextures;}
        if(action.getName() == "TOGGLE_COLLISION")     {m_drawCollision = !m_drawCollision;}
        if(action.getName() == "TOGGLE_GRID")          {m_drawGrid = !m_drawGrid;}
        if(action.getName() == "PAUSE")                {m_paused = !m_paused;}
        if(action.getName() == "QUIT")                 {onEnd();}
        if(action.getName() == "RIGHT")                {m_player->getComponent<CInput>().right = true;}
        if(action.getName() == "LEFT")                 {m_player->getComponent<CInput>().left = true;}
        if(action.getName() == "UP")                   {m_player->getComponent<CInput>().up = true;}
        if(action.getName() == "DOWN")                 {m_player->getComponent<CInput>().down = true;}
    }
    else if (action.getType() == "END")
    {
        if(action.getName() == "RIGHT")                {m_player->getComponent<CInput>().right = false;}
        if(action.getName() == "LEFT")                 {m_player->getComponent<CInput>().left = false;}
        if(action.getName() == "UP")                   {m_player->getComponent<CInput>().up = false;}
        if(action.getName() == "DOWN")                 {m_player->getComponent<CInput>().down = false;}
    }
}

void Scene_Play::sMovement()
{
    //TODO : implement player movement
    //TODO : implement gravity effect on player
    //TODO: implement the maximum player speed in x and y dir.
    //Note : setting an entity scale.x to -1/1 will make face
    auto& pTransform = m_player->getComponent<CTransform>();
    auto& pInput = m_player->getComponent<CInput>();

    pTransform.prevPos = pTransform.pos;

    Vec2 playerSpeed(0,0);
    if(pInput.right)
    {
        playerSpeed.x +=3;
    }
    if(pInput.left)
    {
        playerSpeed.x -=3;
    }
    if(pInput.up)
    {
        playerSpeed.y -=3;
    }
    if(pInput.down)
    {
        playerSpeed.y +=3;
    }
    pTransform.velocity = playerSpeed;
    pTransform.pos +=pTransform.velocity;
}

void Scene_Play::sLifespan()
{
    //TODO copy lifespan
}

void Scene_Play::sCollision()
{
    //TODO : implement physics::getOverlap -> use it in here
    //TODO : implement bullet / tile collision
    //TODO : implement Player /tile collision and resolutions
            // update CState comp of the player to store whether it is currently
            // on the ground or in air. this will be use by animation system
    //TODO: check to see if player has fallen down a hole (y > height())
    //TODO : dont let the player walk off the left side of the map
}

void Scene_Play::onEnd()
{
    m_game->changeScene("MENU",nullptr,true);
}

void Scene_Play::drawLine(const Vec2 & p1, const Vec2 & p2)
{
    sf::Vertex line[] = {sf::Vector2f(p1.x,p1.y), sf::Vector2f (p2.x,p2.y)};
    m_game->window().draw(line,2,sf::Lines);
}


