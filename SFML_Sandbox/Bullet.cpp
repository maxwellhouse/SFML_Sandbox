#include "Bullet.h"
#include "ResourceBase.h"

tBullet::tBullet() :
    tEntity()
{
}

tBullet::tBullet(const unsigned int x
    , const unsigned int y
    , const int speed
    , const unsigned int damage
    , const std::shared_ptr<tBaseResource>& xResource) :
    tEntity(x, y, speed, xResource)
    , m_Damage(damage)
{
}


tBullet::~tBullet()
{
}

bool tBullet::Update(const unsigned int lag)
{
    // Update animation frame
    return true;
}

void tBullet::Draw(const std::shared_ptr<sf::RenderWindow>& xWindow)
{
    m_xResource->Draw(xWindow);
}
