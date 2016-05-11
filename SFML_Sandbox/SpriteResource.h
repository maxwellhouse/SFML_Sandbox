#pragma once
#include "ResourceBase.h"

#include <memory>

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
    void Move(const int x, const int y);
    void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow);
    std::pair<unsigned int, unsigned int> Size() const;

private:
    int m_Height;
    int m_Width;
    int m_X;
    int m_Y;
    sf::Sprite* m_pSprite;
};