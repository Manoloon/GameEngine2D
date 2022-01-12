//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_SCENE_H
#define GAMEENGINE2D_SCENE_H
#include "CommonHeaders.h"
#include "GameEngine.h"
#include "EntityManager.h"
#include "Assets.h"
#include "Action.h"

class Scene
{
public:
    Scene();
    explicit Scene(GameEngine * gameEngine):m_game(gameEngine){}
protected:
    GameEngine * m_game;
    EntityManager m_entityManager;
    int m_currentFrame;
    std::map<int,std::string> m_actionMap;
    bool m_paused;
    bool m_hasEnded;
public:
    virtual void update()=0;
    virtual void sDoAction(Action & action)=0;
    virtual void sRender()=0;
    void simulate(int);
    void doAction(Action);
    void registerAction(Action);

    void setPaused(bool paused);
    size_t getWidth() const;
    size_t getHeight() const;
    size_t getCurrentFrame()const;


};


#endif //GAMEENGINE2D_SCENE_H
