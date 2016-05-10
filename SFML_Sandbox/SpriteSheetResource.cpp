#include "SpriteSheetResource.h"
#include <SFML/Graphics.hpp>

tSpriteSheetResource::tSpriteSheetResource(const std::string& path) :
    tBaseResource(path, tBaseResource::ert_SpriteSheet)
{
    m_pTexture = nullptr;
}

tSpriteSheetResource::~tSpriteSheetResource()
{
    UnloadResource();
}

void tSpriteSheetResource::UnloadResource()
{
    delete m_pTexture;
    m_pTexture = nullptr;
}

bool tSpriteSheetResource::LoadResource()
{
    bool success = true;
    if (IsLoaded() == false)
    {
        m_pTexture = new sf::Texture();
        success = m_pTexture->loadFromFile(Path());
    }

    SetLoaded(success);
    return success;
}

const sf::Texture* tSpriteSheetResource::Texture() const
{
    return m_pTexture;
}

std::pair<int, int> tSpriteSheetResource::Size() const
{
    std::pair<int, int> size = std::make_pair<int, int>(0, 0);
    if (m_pTexture)
    {
        size = std::make_pair<int, int>(m_pTexture->getSize().x, m_pTexture->getSize().y);
    }
    return size;
}