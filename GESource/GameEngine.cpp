//
// Created by Manoloon on 15/12/2021.
//

#include "GameEngine.h"

void GameEngine::MainLoop()
{
    m_entityManager.Update();
    // add systems
    // sUserInput();
    // sMovement();
    // sCollision();
    // sRender();
    m_currentFrame++;
}
