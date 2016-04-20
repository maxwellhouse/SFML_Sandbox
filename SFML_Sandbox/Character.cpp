#include "Character.h"



tCharacter::tCharacter() :
    tActor()
    , m_Health(0)
{
}

tCharacter::tCharacter(const int x
                     , const int y
                     , const unsigned int health
                     , const std::shared_ptr<tResourceBase>& xResource) :
    tActor(x, y, xResource)
    , m_Health(health)
{
}


tCharacter::~tCharacter()
{
}
