//
// Created by Manoloon on 17/12/2021.
//

#include "FVec2.h"

Vec2 Vec2::operator+(const Vec2 &rval) const
{
        return Vec2(x+rval.x, y+rval.y);
}

Vec2 Vec2::operator*(const float &scale) const
{
    return {(x * scale), (y * scale)};
}

void Vec2::operator+=(const Vec2 &rval)
{
    return; // no puede retornar un rvalue.
}

Vec2 &Vec2::scale(float scale)
{
    x *= scale; y *= scale; return *this;
}

Vec2 &Vec2::add(float val)
{
    x += val; y += val; return *this;
}

float Vec2::distance(const Vec2 &rval)
{
    return (this->x - rval.x*rval.x)+(this->y -rval.y*rval.y);
}

