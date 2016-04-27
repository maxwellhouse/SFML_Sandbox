#include "Character.h"
#include "ResourceBase.h"
#include "GameEngine.h"
#include "Bullet.h"
#include "ResourceManager.h"

tCharacter::tCharacter() :
    tActor()
    , m_Health(0)
    , m_Speed(0)
    , m_CurrentBulletType("default_bullet_type")
{
}

tCharacter::tCharacter(const int x
                     , const int y
                     , const unsigned int health
                     , const unsigned int speed
                     , const std::shared_ptr<tBaseResource>& xResource) :
    tActor(x, y, xResource)
    , m_Health(health)
    , m_Speed(speed)
    , m_CurrentBulletType("default_bullet_type")
{
}


tCharacter::~tCharacter()
{
}


void tCharacter::Draw(sf::RenderWindow* pWindow, const unsigned int lag)
{
    m_xResource->Draw(pWindow, lag);
}

bool tCharacter::MoveDown()
{
    bool success = false;
    if ((m_YPos + m_Speed) <= tGameEngine::Instance()->CurrentHeight())
    {
        m_YPos += m_Speed;
        success = true;
    }
    return success;
}

bool tCharacter::MoveLeft()
{
    bool success = false;
    if ((m_XPos - m_Speed) > tGameEngine::Instance()->CurrentWidth())
    {
        m_XPos -= m_Speed;
        success = true;
    }
    return success;
}

bool tCharacter::MoveRight()
{
    bool success = false;
    if ((m_XPos + m_Speed) <= tGameEngine::Instance()->CurrentWidth())
    {
        m_XPos += m_Speed;
        success = true;
    }
    return success;
}

bool tCharacter::MoveUp()
{
    bool success = false;
    if ((m_YPos - m_Speed) > tGameEngine::Instance()->CurrentHeight())
    {
        m_YPos -= m_Speed;
        success = true;
    }
    return success;
}

bool tCharacter::Shoot()
{
    bool success = false;
    if ((m_Projectiles.size() + 1) <= tGameEngine::MaxBulletsPerActor())
    {
        m_Projectiles.push_back(std::make_shared<tBullet>(m_XPos, m_YPos, rand() % 10, tGameEngine::ResourceManager()->GetResource(m_CurrentBulletType)));
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