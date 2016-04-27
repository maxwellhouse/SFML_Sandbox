#pragma once
#include "Actor.h"

class tBullet : public tActor
{
public:
    tBullet();
    tBullet(const int x
        , const int y
        , const unsigned int speed
        , const std::shared_ptr<tBaseResource>& xResource);

    virtual ~tBullet();

    bool MoveLeft();
    bool MoveRight();
    bool MoveUp();
    bool MoveDown();
    bool Shoot();

    bool Update(const unsigned int lag);
    void Draw(sf::RenderWindow* pWindow, const unsigned int lag);

private:
    unsigned int m_Speed;
};
