#pragma once
#include <vector>
#include "ResourceBase.h"

//Forward declares
class tSpriteResource;
namespace sf
{
    class Sprite;
}
class tAnimationResource : public tBaseResource
{
public:
    tAnimationResource(const std::string& id);
    virtual ~tAnimationResource();

    void AddFrame(tSpriteResource* pSprite);

public:
    bool LoadResource();
    void UnloadResource();
    bool update();
    void Draw(sf::RenderWindow* pWindow);

private:
    std::vector<tSpriteResource*> m_Frames;
    int m_CurrentFrame;
};