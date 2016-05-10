#include "Entity.h"
#include "ResourceBase.h"
#include "GameEngine.h"
#include "Locator.h"

tEntity::tEntity() :
      m_XPos(0)
    , m_YPos(0)
    , m_Speed(0)
{
    m_xResource = nullptr;
}

tEntity::tEntity(const int x
               , const int y
               , const int speed
               , const std::shared_ptr<tBaseResource>& xResource
               , const std::shared_ptr<tGameEngine>& xEngine) :
      m_XPos(x)
    , m_YPos(y)
    , m_Speed(speed)
    , m_xResource(xResource)
    , m_xGameEngine(xEngine)
{
    m_xResource->Move(m_XPos, m_YPos);
}

tEntity::~tEntity()
{
}

bool tEntity::MoveLeft()
{
    return OffsetMove(-m_Speed, 0);
}
bool tEntity::MoveRight()
{
    return OffsetMove(m_Speed, 0);
}
bool tEntity::MoveUp()
{
    return OffsetMove(0, -m_Speed);
}
bool tEntity::MoveDown()
{
    return OffsetMove(0, m_Speed);
}

bool tEntity::Move(const int x, const int y)
{
    bool success = false;
    if ((x + m_xResource->Size().first < m_xGameEngine->CurrentWidth() && x >= 0) 
       && (y + m_xResource->Size().second < m_xGameEngine->CurrentHeight() && y >= 0))
    {
        m_XPos = x;
        m_YPos = y;
        m_xResource->Move(m_XPos, m_YPos);
        success = true;
    }
    return success;
}

bool tEntity::OffsetMove(const int x, const int y)
{
    int newX = m_XPos + x;
    int newY = m_YPos + y;

    return Move(newX, newY);
}