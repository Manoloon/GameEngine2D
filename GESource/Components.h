//
// Created by Manoloon on 18/12/2021.
//

#ifndef GAMEENGINE2D_COMPONENTS_H
#define GAMEENGINE2D_COMPONENTS_H
#include "CommonHeaders.h"

struct CTransform
{
    Vec2 pos = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    float angle = 0;

    CTransform(const Vec2 &p, const Vec2 &vel, float ang) : pos(p), velocity(vel), angle(ang)
    {}
};

struct CShape
{
    sf::CircleShape shape;

    CShape(float radius, int points, const sf::Color &colorFill, const sf::Color &colOutline, float thickness)
            : shape(radius, points)
    {
        shape.setFillColor(colorFill);
        shape.setOutlineColor(colOutline);
        shape.setOutlineThickness(thickness);
        shape.setOrigin(radius, radius);
    }
};

struct CCollision
{
    float radius = 0;

    CCollision(float r) : radius(r)
    {}
};

struct CScore
{
    int score = 0;

    CScore(int s) : score(s)
    {}
};

struct CLifespan
{
    int remaining = 0;
    int total = 0;

    CLifespan(int remain, int total)
            : remaining(remain), total(total)
    {}
};

struct CInput
{
    bool up = false;
    bool left= false;
    bool right= false;
    bool down=false;
    bool shoot= false;
    bool SecShoot= false;
    CInput(){}
};
#endif //GAMEENGINE2D_COMPONENTS_H
