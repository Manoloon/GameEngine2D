//
// Created by Manoloon on 18/12/2021.
//

#ifndef GAMEENGINE2D_COMPONENTS_H
#define GAMEENGINE2D_COMPONENTS_H
#include "CommonHeaders.h"
#include "Animation.h"

struct Component
        {

        };

struct CState : public Component
{
    std::string state = "OnAir";
    CState(){}
    CState(const std::string & s) : state(s){}
};

struct CTransform : public Component
{
    Vec2 pos = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    float angle = 0;

    CTransform(const Vec2 &p, const Vec2 &vel, float ang) : pos(p), velocity(vel), angle(ang)
    {}
};

struct CShape : public Component
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

struct CCollision : public Component
{
    float radius = 0;
    sf::CircleShape shape;
    explicit CCollision(float r) : radius(r)
    {
        shape.setOutlineColor(sf::Color::Red);
        shape.setOrigin(radius,radius);
        shape.setOutlineThickness(2);
    }
};

struct CScore : public Component
{
    int score = 0;

    explicit CScore(int s) : score(s){}
};

struct CLifespan : public Component
{
    int remaining = 0;
    int total = 0;

    CLifespan(int total)
            : remaining(total), total(total)
    {}
};

struct CInput : public Component
{
    bool up = false;
    bool left= false;
    bool right= false;
    bool down=false;
    bool shoot= false;
    bool SecShoot= false;
    CInput()= default;
};

struct CGravity : public Component
        {
            float gravity = 0;
            CGravity(){}
            CGravity(float g):gravity(g){}
        };

struct CAnimation : public Component
        {
            Animation animation;
            bool repeat = false;
            CAnimation(){}
            CAnimation(const Animation & a, bool r): animation(a), repeat(r){}
        };

#endif //GAMEENGINE2D_COMPONENTS_H
