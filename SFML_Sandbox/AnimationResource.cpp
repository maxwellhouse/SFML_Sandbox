#include "AnimationResource.h"
#include "SpriteResource.h"

tAnimationResource::tAnimationResource(const std::string& path, const sf::Time& frameTime) :
    tBaseResource(path, ert_Animation)
    , m_CurrentFrame(0)
    , m_FrameTime(frameTime)
    , m_CurrentTime(sf::Time::Zero)
{
}

tAnimationResource::~tAnimationResource()
{
    m_Frames.clear();
}

void tAnimationResource::AddFrame(tSpriteResource* pSprite)
{
    m_Frames.push_back(pSprite);
}

bool tAnimationResource::LoadResource()
{
    bool success = false;
    for (std::vector<tSpriteResource*>::const_iterator it = m_Frames.begin(); it != m_Frames.end(); ++it)
    {
        if ((*it)->LoadResource() == false)
        {
            success = false;
            break;
        }
    }
    success = true;
    SetLoaded(success);
    return success;
}

void tAnimationResource::UnloadResource()
{
    for (std::vector<tSpriteResource*>::const_iterator it = m_Frames.begin(); it != m_Frames.end(); ++it)
    {
        (*it)->UnloadResource();
    }
}

bool tAnimationResource::UpdateFrame(const unsigned int lag)
{
    m_CurrentTime += sf::milliseconds(lag);
    if (m_CurrentTime >= m_FrameTime)
    {
        m_CurrentTime = sf::milliseconds(m_CurrentTime.asMilliseconds() % m_FrameTime.asMilliseconds());
        m_CurrentFrame++;
        if (m_CurrentFrame >= m_Frames.size())
        {
            m_CurrentFrame = 0;
        }
    }
    return true;
}

void tAnimationResource::Draw(const std::shared_ptr<sf::RenderWindow>& xWindow)
{
    if (IsLoaded() == true)
    {
        m_Frames[m_CurrentFrame]->Draw(xWindow);
    }
}

void tAnimationResource::Move(const int x, const int y)
{
    for (std::vector<tSpriteResource*>::const_iterator it = m_Frames.begin(); it != m_Frames.end(); ++it)
    {
        (*it)->Move(x, y);
    }
}

std::pair<int, int> tAnimationResource::Size() const
{
    std::pair<int, int> size = std::make_pair<int, int>(0, 0);
    if (m_Frames.size() > 0)
    {
        size = (*m_Frames.begin())->Size();
    }
    return size;
}