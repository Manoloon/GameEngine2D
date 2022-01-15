//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_SCENE_H
#define GAMEENGINE2D_SCENE_H
#include "CommonHeaders.h"
#include "EntityManager.h"
#include "Action.h"

class GameEngine;

typedef std::map<int,std::string> ActionMap;

class Scene
{
public:
    Scene();
    explicit Scene(GameEngine * gameEngine):m_game(gameEngine){}
protected:
    GameEngine *            m_game = nullptr;
    EntityManager           m_entityManager;
    size_t                  m_currentFrame=0;
    ActionMap               m_actionMap;
    bool                    m_paused = false;
    bool                    m_hasEnded = false;
public:
    virtual void update()=0;
    virtual void sDoAction(Action & action)=0;
    virtual void sRender()=0;
    void simulate(int);
    void doAction(Action);
    void registerAction(int inputKey ,std::string actionName);

    void setPaused(bool paused);
    size_t getWidth() const;
    size_t getHeight() const;
    size_t getCurrentFrame()const;
    std::map<int,std::string> getActionMap() const;


};


#endif //GAMEENGINE2D_SCENE_H
