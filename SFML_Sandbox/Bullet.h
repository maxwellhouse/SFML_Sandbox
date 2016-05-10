#pragma once
#include "Entity.h"

//Forward declares
class tGameEngine;

class tBullet : private tEntity
{
public:
    tBullet();
    tBullet(const unsigned int x
        , const unsigned int y
        , const int speed
        , const unsigned int damage
        , const std::shared_ptr<tBaseResource>& xResource
        , const std::shared_ptr<tGameEngine>& xEngine);

    virtual ~tBullet();

    bool Update(const unsigned int lag);
    void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow);

private:
    unsigned int m_Speed;
    unsigned int m_Damage;
};
