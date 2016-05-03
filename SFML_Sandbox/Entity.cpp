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

tEntity::tEntity(const int x, const int y, const int speed, const std::shared_ptr<tBaseResource>&xResource) :
      m_XPos(x)
    , m_YPos(y)
    , m_Speed(speed)
    , m_xResource(xResource)
{
    m_xResource->Move(m_XPos, m_YPos);
}

tEntity::~tEntity()
{
}

bool tEntity::MoveLeft()
{
    bool moveSuccessful = false;
    if (m_XPos != 0)
    {
        m_XPos -= m_Speed;
        if (m_XPos < 0)
        {
            m_XPos = 0;
        }
        m_xResource->Move(m_XPos, m_YPos);
        moveSuccessful = true;
    }
    return moveSuccessful;
}
bool tEntity::MoveRight()
{
    bool moveSuccessful = false;
    tGameEngine* pEngine = tGameEngine::Instance();
    if (pEngine)
    {
        if (m_XPos != pEngine->CurrentWidth())
        {
            m_XPos += m_Speed;
            if (m_XPos > pEngine->CurrentWidth())
            {
                m_XPos = pEngine->CurrentWidth();
            }
            m_xResource->Move(m_XPos, m_YPos);
            moveSuccessful = true;
        }
    }
    else
    {
        std::string err("Failed to obtain game engine.");
        tLocator::GetLogger().Log(err);
    }
    return moveSuccessful;
}
bool tEntity::MoveUp()
{
    bool moveSuccessful = false;
    if (m_YPos != 0)
    {
        m_YPos -= m_Speed;
        if (m_YPos < 0)
        {
            m_YPos = 0;
        }
        m_xResource->Move(m_XPos, m_YPos);
        moveSuccessful = true;
    }
    return moveSuccessful;
}
bool tEntity::MoveDown()
{
    bool moveSuccessful = false;
    tGameEngine* pEngine = tGameEngine::Instance();
    if (pEngine)
    {
        if (m_YPos != pEngine->CurrentHeight())
        {
            m_YPos += m_Speed;
            if (m_YPos  > pEngine->CurrentHeight())
            {
                m_YPos = pEngine->CurrentHeight();
            }
            m_xResource->Move(m_XPos, m_YPos);
            moveSuccessful = true;
        }
    }
    else
    {
        std::string err("Failed to obtain game engine.");
        tLocator::GetLogger().Log(err);
    }
    return moveSuccessful;
}