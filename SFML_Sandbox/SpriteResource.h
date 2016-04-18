#pragma once
#include "ResourceBase.h"

//Forward declare
namespace sf
{
    class Sprite;
}

class tSpriteResource : public tBaseResource
{
public:
    tSpriteResource(const std::string& id
                   , const int xPos
                   , const int yPos
                   , const int width
                   , const int height);
    virtual ~tSpriteResource();
public:
    bool LoadResource();
    void UnloadResource();
    bool update();
    void Draw(sf::RenderWindow* window);

private:
    int m_Height;
    int m_Width;
    int m_X;
    int m_Y;
    sf::Sprite* m_pSprite;
};