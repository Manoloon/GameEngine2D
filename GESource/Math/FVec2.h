//
// Created by Manoloon on 12/12/2021.
//

#ifndef GAMEENGINE2D_FVEC2_H
#define GAMEENGINE2D_FVEC2_H
#include <ostream>
struct Vec2
{
    float x;
    float y;
    Vec2()=default;
    Vec2(float xin,float yin);
    bool operator == (const Vec2 & rvalue) const;
    bool operator != (const Vec2 & rvalue) const;
    // no se usaria ni const ni & porque float es un valor minimo , mejor hacer copia de el.
    Vec2 operator + (const Vec2 & rvalue) const;
    Vec2 operator - (const Vec2 & rvalue) const;
    Vec2 operator / (float val) const;
    Vec2 operator * (float scale) const;

    void operator += (const Vec2 & rvalue);
    void operator -= (const Vec2 & rvalue);
    void operator *= (float val);
    void operator /= (float val);

    // Functions
    /**
     * @param rvalue = target vector
     * @return float : Distance
     */
    float dist(const Vec2& rvalue) const ;
    float getVectorLength() const;
    Vec2 ForwardTo(const Vec2& Target) const;
    Vec2 getVelocity(float speed,float angle) const;
    Vec2 getVelocity(float speed,const Vec2& targetPos) const;

    float getAngle(const Vec2& TargetPos)const;
    Vec2 normalize() const;
    Vec2 scale(float scale);
    Vec2 add(float val);


    // esta funcion hace que se pueda imprimir con cout.
    friend std::ostream& operator << (std::ostream& stream, const Vec2& vector)
    {
        return stream << vector.x << " " << vector.y << "\n";
    }
};
#endif //GAMEENGINE2D_FVEC2_H
