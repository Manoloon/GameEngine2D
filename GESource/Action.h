//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_ACTION_H
#define GAMEENGINE2D_ACTION_H
#include "CommonHeaders.h"
class Action
{
private:
   sf::Sprite           m_sprite;
   int                  m_frameCount;
   int                  m_currentFrame;
   int                  m_speed;
   Vec2                 m_size;

   std::string          m_name;
   std::string          m_type;
public:
    Action(){}
    Action(const std::string & name, const std::string & type):m_name(name),m_type(type){}

    const std::string &       getType() const;
    const std::string &       getName() const;

    void                      update();
    bool                      hasEnded();
    const Vec2 &              getSize() const;
    const sf::Sprite &        getSprite() const;
};


#endif //GAMEENGINE2D_ACTION_H
