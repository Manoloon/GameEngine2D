//
// Created by Manoloon on 12/12/2021.
//

#ifndef GAMEENGINE2D_FVEC2_H
#define GAMEENGINE2D_FVEC2_H
#include <ostream>
struct Vec2
{
    float x,y;
    Vec2(float xin,float yin):x(xin),y(yin){};
    bool operator == (const Vec2 & rval) const
    {
        return (x==rval.x) && (y==rval.y);
    }
    // no se usaria ni const ni & porque float es un valor minimo , mejor hacer copia de el.
    Vec2 operator + (const Vec2 & rval) const
    {
        return Vec2(x+rval.x, y+rval.y);
    }
    Vec2 operator * (const float & scale) const
    {
        return {(x * scale), (y * scale)};
    }
    void operator += (const Vec2 & rval);
    Vec2& scale(float scale){x *= scale; y *= scale; return *this;}
    Vec2& add(float val) {x += val; y += val; return *this;}
    float distance(const Vec2& rval)
    {
        return (this->x - rval.x)+(this->y -rval.y);
    }
    // esta funcion hace que se pueda imprimir con cout.
    friend std::ostream& operator << (std::ostream& stream, const Vec2& vector)
    {
        return stream << vector.x << " " << vector.y << "\n";
    }
};
#endif //GAMEENGINE2D_FVEC2_H
