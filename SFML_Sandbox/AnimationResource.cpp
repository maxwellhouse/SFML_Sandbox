#include "AnimationResource.h"
#include "SpriteResource.h"

tAnimationResource::tAnimationResource(const std::string& path) :
    tBaseResource(path, ert_Animation)
    , m_CurrentFrame(0)
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

bool tAnimationResource::update()
{
    m_CurrentFrame++;
    if (m_CurrentFrame / 4 >= (m_Frames.size()-1))
    { 
        m_CurrentFrame = 0;
    }
    return true;
}

void tAnimationResource::Draw(sf::RenderWindow* pWindow)
{
    if (IsLoaded() == true)
    {
        m_Frames[m_CurrentFrame / 4]->Draw(pWindow);
    }
}