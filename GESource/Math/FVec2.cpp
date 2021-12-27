//
// Created by Manoloon on 17/12/2021.
//

#include "FVec2.h"
#include <cmath>

Vec2::Vec2(float xin, float yin)
        :x(xin),y(yin){}

bool Vec2::operator==(const Vec2 &rvalue) const
{
    return (x == rvalue.x) && (y == rvalue.y);
}

bool Vec2::operator!=(const Vec2 &rvalue) const
{
    return (x != rvalue.x) || (y != rvalue.y);
}

Vec2 Vec2::operator+(const Vec2 &rvalue) const
{
    return Vec2(x + rvalue.x, y + rvalue.y);
}

Vec2 Vec2::operator-(const Vec2 &rvalue) const
{
    return Vec2(x - rvalue.x, y - rvalue.y);
}

Vec2 Vec2::operator/(const float val) const
{
    if(val <=0){return {0,0};}
    return {x /val,y/val};
}

Vec2 Vec2::operator*(const float scale) const
{
    return {(x * scale), (y * scale)};
}

void Vec2::operator+=(const Vec2 &rvalue)
{
    x= x + rvalue.x;
    y= y + rvalue.y;
}

void Vec2::operator-=(const Vec2 &rvalue)
{
    x= x - rvalue.x;
    y= y - rvalue.y;
}

void Vec2::operator*=(const float val)
{
    x=x*val;
    y=y*val;
}

void Vec2::operator/=(const float val)
{
    //TODO : ver que no divida por cero.
    if(val <=0){return;}
    x=x/val;
    y=y/val;
}

Vec2 Vec2::scale(float scale)
{
    x *= scale; y *= scale; return *this;
}

Vec2 Vec2::add(float val)
{
    x += val; y += val; return *this;
}

float Vec2::dist(const Vec2 &rvalue) const
{
    //return (this->x - rvalue.x * rvalue.x) + (this->y - rvalue.y * rvalue.y);
    return ((rvalue.x - this->x)  * (rvalue.x - this->x))  + ((rvalue.y - this->y)  * (rvalue.y - this->y));
}

Vec2 Vec2::ForwardTo(const Vec2& Target) const
{
    return {Target.x -this->x,Target.y - this->y};
}

Vec2 Vec2::normalize() const
{
    return {this->x / getVectorLength(), this->y / getVectorLength()};
}

float Vec2::getVectorLength() const
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

float Vec2::getAngle(const Vec2& TargetPos) const
{
    return atan2f(TargetPos.y-this->y,TargetPos.x-this->x);
}

Vec2 Vec2::getVelocity(float speed,float angle) const
{
    return {speed *cosf(angle),speed * sinf(angle)} ;
}

Vec2 Vec2::getVelocity(float speed,const Vec2& targetPos) const
{
    return {speed * targetPos.normalize().x,speed * targetPos.normalize().y};
}

float Vec2::distSquare(const Vec2 &rvalue) const
{
    Vec2 diffD = {rvalue.x - this->x,rvalue.y - this->y};
    return diffD.x * diffD.x + diffD.y * diffD.y;
}






