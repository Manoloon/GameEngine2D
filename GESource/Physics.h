//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_PHYSICS_H
#define GAMEENGINE2D_PHYSICS_H
#include "CommonHeaders.h"
#include "Entity.h"

class Physics
{
    Vec2 getOverlap(std::shared_ptr<Entity> a , std::shared_ptr<Entity> b);
    Vec2 getPreviousOverlap(std::shared_ptr<Entity> a , std::shared_ptr<Entity> b);
};


#endif //GAMEENGINE2D_PHYSICS_H
