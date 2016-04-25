#pragma once
#include "Actor.h"

class tCharacter : public tActor
{
public:
    tCharacter();
    tCharacter(const int x
        , const int y
        , const unsigned int health
        , const std::shared_ptr<tBaseResource>& xResource);

    virtual ~tCharacter();

    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();
    bool shoot();

private:
    unsigned int m_Health;
};

