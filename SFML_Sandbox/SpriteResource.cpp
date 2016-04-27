#include <SFML/Graphics.hpp>
#include "SpriteResource.h"
#include "SpriteSheetResource.h"
#include "GameEngine.h"
#include "ResourceManager.h"

tSpriteResource::tSpriteResource(const std::string& path
                             , const int xPos
                             , const int yPos
                             , const int width
                             , const int height) :
    tBaseResource(path, ert_Sprite)
    , m_Width(width)
    , m_Height(height)
    , m_X(xPos)
    , m_Y(yPos)
{
    m_pSprite = nullptr;
}
tSpriteResource::~tSpriteResource()
{
    UnloadResource();
}
bool tSpriteResource::LoadResource()
{
    bool success = false;
    if (IsLoaded() == false)
    {
        std::shared_ptr<tSpriteSheetResource> xSpriteSheet;
        xSpriteSheet = std::dynamic_pointer_cast<tSpriteSheetResource>(tGameEngine::ResourceManager()->GetResource(Path()));
        if (xSpriteSheet != nullptr )
        {
            m_pSprite = new sf::Sprite(*xSpriteSheet->Texture(), sf::IntRect(m_X,m_Y, m_Width, m_Height));
            success = (m_pSprite != nullptr);
        }
    }

    SetLoaded(success);
    return success;
}
void tSpriteResource::UnloadResource()
{
    delete m_pSprite;
    m_pSprite = nullptr;
    SetLoaded(false);
}

void tSpriteResource::Draw(sf::RenderWindow* pWindow, const unsigned int)
{
    if (IsLoaded() == true)
    {
        pWindow->draw(*m_pSprite);
    }
}

