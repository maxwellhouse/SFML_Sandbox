#pragma once
#include "Actor.h"

// Forward declares
class tBullet;

class tCharacter : public tActor
{
public:
    tCharacter();
    tCharacter(const int x
        , const int y
        , const unsigned int health
        , const unsigned int speed
        , const std::shared_ptr<tBaseResource>& xResource);

    virtual ~tCharacter();

    bool MoveLeft();
    bool MoveRight();
    bool MoveUp();
    bool MoveDown();
    bool Shoot();

    bool Update(const unsigned int lag);
    void Draw(sf::RenderWindow* pWindow, const unsigned int lag);

private:
    unsigned int m_Health;
    unsigned int m_Speed;
    std::string m_CurrentBulletType;
    std::vector<std::shared_ptr<tBullet> > m_Projectiles;
};

