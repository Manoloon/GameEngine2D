//
// Created by Manoloon on 12/12/2021.
//

#ifndef GAMEENGINE2D_FVEC2_H
#define GAMEENGINE2D_FVEC2_H
#include <ostream>
struct Vec2
{
    float x,y;
    Vec2();
    Vec2(float xin,float yin);
    bool operator == (const Vec2 & rval) const;
    bool operator != (const Vec2 & rval) const;
    // no se usaria ni const ni & porque float es un valor minimo , mejor hacer copia de el.
    Vec2 operator + (const Vec2 & rval) const;
    Vec2 operator - (const Vec2 & rval) const;
    Vec2 operator / (const float val) const;
    Vec2 operator * (const float scale) const;

    void operator += (const Vec2 & rval);
    void operator -= (const Vec2 & rval);
    void operator *= (const float val);
    void operator /= (const float val);

    // Functions
    float distance(const Vec2& rval) const ;
    Vec2 scale(float scale);
    Vec2 add(float val);


    // esta funcion hace que se pueda imprimir con cout.
    friend std::ostream& operator << (std::ostream& stream, const Vec2& vector)
    {
        return stream << vector.x << " " << vector.y << "\n";
    }
};
#endif //GAMEENGINE2D_FVEC2_H
