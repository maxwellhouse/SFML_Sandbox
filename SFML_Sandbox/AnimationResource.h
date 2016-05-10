#pragma once
#include <vector>
#include "ResourceBase.h"
#include <SFML/Graphics.hpp>

//Forward declares
class tSpriteResource;
namespace sf
{
    class Sprite;
}
class tAnimationResource : public tBaseResource
{
public:
    tAnimationResource(const std::string& id, const sf::Time& timeFrame);
    virtual ~tAnimationResource();

    void AddFrame(tSpriteResource* pSprite);

public:
    bool LoadResource();
    void UnloadResource();
    bool UpdateFrame(const unsigned int lag);
    void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow);
    void Move(const int x, const int y);
    std::pair<int, int> Size() const;
private:
    std::vector<tSpriteResource*> m_Frames;
    unsigned int m_CurrentFrame;
    sf::Time m_FrameTime;
    sf::Time m_CurrentTime;
};