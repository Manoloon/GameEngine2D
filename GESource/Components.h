//
// Created by Manoloon on 18/12/2021.
//

#ifndef GAMEENGINE2D_COMPONENTS_H
#define GAMEENGINE2D_COMPONENTS_H
#include <SFML/Graphics.hpp>
struct CTransform
    {

    };

struct CShape
    {
    sf::CircleShape shape;
    CShape(){}
    };

struct CCollision
    {
        float m_radius;
    };

struct CScore
    {
        int m_score;
    };
struct CInput
    {

    };
#endif //GAMEENGINE2D_COMPONENTS_H
