#pragma once
#include "Entity.h"

// Forward declares
class tBullet;

class tCharacter : public tEntity
{
public:
    tCharacter();
    tCharacter(const int x
        , const int y
        , const unsigned int health
        , const unsigned int speed
        , const std::shared_ptr<tBaseResource>& xResource);

    virtual ~tCharacter();

    bool Shoot();

    bool Update(const unsigned int lag);
    void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow);

private:
    unsigned int m_Health;
    std::string m_CurrentBulletType;
    std::vector<std::shared_ptr<tBullet> > m_Projectiles;
};

