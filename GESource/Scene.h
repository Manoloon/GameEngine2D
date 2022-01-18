//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_SCENE_H
#define GAMEENGINE2D_SCENE_H
#include "CommonHeaders.h"
#include "EntityManager.h"
#include "Action.h"

class GameEngine;

using ActionMap = std::map<int,std::string>;

class Scene
{
public:
    Scene()=default;

    explicit Scene(GameEngine * gameEngine);

protected:
    GameEngine *            m_game = nullptr;
    EntityManager           m_entityManager;
    size_t                  m_currentFrame=0;
    ActionMap               m_actionMap;
    bool                    m_paused = false;
    bool                    m_hasEnded = false;
public:
    void doAction(const Action & action);
    virtual void update()=0;
    virtual void sRender()=0;
    virtual void sDoAction(const Action & action)=0;
    void simulate(int);
    void registerAction(int inputKey ,std::string actionName);

    void setPaused(bool paused);
    size_t getWidth() const;
    size_t getHeight() const;
    size_t getCurrentFrame()const;
    std::map<int,std::string> getActionMap() const;

   // virtual ~Scene();

};


#endif //GAMEENGINE2D_SCENE_H
