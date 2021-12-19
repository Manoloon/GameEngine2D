//
// Created by Manoloon on 17/12/2021.
//

#include "FVec2.h"
#include <math.h>

Vec2::Vec2(){}

Vec2::Vec2(float xin, float yin)
        :x(xin),y(yin){}

bool Vec2::operator==(const Vec2 &rval) const
{
    return (x==rval.x) && (y==rval.y);
}

bool Vec2::operator!=(const Vec2 &rval) const
{
    return (x!=rval.x)||(y!=rval.y);
}

Vec2 Vec2::operator+(const Vec2 &rval) const
{
    return Vec2(x+rval.x, y+rval.y);
}

Vec2 Vec2::operator-(const Vec2 &rval) const
{
    return Vec2(x-rval.x, y-rval.y);
}

Vec2 Vec2::operator/(const float val) const
{
    return Vec2();
}

Vec2 Vec2::operator*(const float scale) const
{
    return {(x * scale), (y * scale)};
}


void Vec2::operator+=(const Vec2 &rval)
{
    x=x+rval.x;
    y=y+rval.y;
}

void Vec2::operator-=(const Vec2 &rval)
{
    x=x-rval.x;
    y=y-rval.y;
}

void Vec2::operator*=(const float val)
{
    x=x*val;
    y=y*val;
}

void Vec2::operator/=(const float val)
{
    x=x/val;
    y=y/val;
    //TODO : ver que no divida por cero.
}

Vec2 Vec2::scale(float scale)
{
    x *= scale; y *= scale; return *this;
}

Vec2 Vec2::add(float val)
{
    x += val; y += val; return *this;
}

float Vec2::distance(const Vec2 &rval) const
{
    return (this->x - rval.x*rval.x)+(this->y -rval.y*rval.y);
}





