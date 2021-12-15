//
// Created by Manoloon on 15/12/2021.
//

#ifndef GAMEENGINE2D_GAMEENGINE_H
#define GAMEENGINE2D_GAMEENGINE_H
#include "EntityManager.h"

class GameEngine
{
    EntityManager m_entityManager;
    size_t m_currentFrame =0;
    void MainLoop();
};


#endif //GAMEENGINE2D_GAMEENGINE_H
