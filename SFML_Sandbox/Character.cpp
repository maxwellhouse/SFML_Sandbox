#include "Character.h"
#include "ResourceBase.h"
#include "GameEngine.h"
#include "Bullet.h"
#include "ResourceManager.h"

tCharacter::tCharacter() :
    tEntity()
    , m_Health(0)
    , m_CurrentBulletType("default_bullet_type")
{
}

tCharacter::tCharacter(const int x
                     , const int y
                     , const unsigned int health
                     , const unsigned int speed
                     , const std::shared_ptr<tBaseResource>& xResource) :
    tEntity(x, y, speed, xResource)
    , m_Health(health)
    , m_CurrentBulletType("default_bullet_type")
{
}


tCharacter::~tCharacter()
{
}


void tCharacter::Draw(const std::shared_ptr<sf::RenderWindow>& xWindow)
{
    m_xResource->Draw(xWindow);
}
bool tCharacter::Shoot()
{
    bool success = false;
    if ((m_Projectiles.size() + 1) <= tGameEngine::MaxBulletsPerActor())
    {
        m_Projectiles.push_back(std::make_shared<tBullet>(m_XPos
                                                         , m_YPos
                                                         , rand() % 10
                                                         , rand() % 1000
                                                         , tGameEngine::ResourceManager()->GetResource(m_CurrentBulletType)));
        success = true;
    }
    return success;
}

bool tCharacter::Update(const unsigned int lag)
{
    bool success = false;
    for (std::vector<std::shared_ptr<tBullet> >::iterator bulletIt = m_Projectiles.begin(); bulletIt != m_Projectiles.end(); ++bulletIt)
    {
        success = (*bulletIt)->Update(lag);
        // TODO: If success if false here log error somehow.
    }
    return success;
}