#include "Actor.h"

tActor::tActor() :
      m_XPos(0)
    , m_YPos(0)
{
    m_xResource = nullptr;
}

tActor::tActor(const int x, const int y, const std::shared_ptr<tResourceBase>&xResource) :
      m_XPos(x)
    , m_YPos(y)
    , m_xResource(xResource)
{
}

tActor::~tActor()
{
}
