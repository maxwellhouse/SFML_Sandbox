#include "Bullet.h"

tBullet::tBullet() :
    tActor()
{
}

tBullet::tBullet(const int x
    , const int y
    , const unsigned int speed
    , const std::shared_ptr<tBaseResource>& xResource) :
    tActor(x, y, xResource)
    , m_Speed(speed)
{
}


tBullet::~tBullet()
{
}
