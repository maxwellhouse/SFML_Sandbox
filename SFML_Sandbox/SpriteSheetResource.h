#pragma once
#include "ResourceBase.h"

//Forward declare
namespace sf
{
    class Texture;
    class RenderWindow;
}

class tSpriteSheetResource : public tBaseResource
{
public:
    tSpriteSheetResource(const std::string& id);
    virtual ~tSpriteSheetResource();

public:
    const sf::Texture* Texture() const;
    bool LoadResource();
    void UnloadResource();
    void Update(const unsigned int) {};
    void Draw(const std::shared_ptr<sf::RenderWindow>&) {};

private:
    sf::Texture* m_pTexture;
};
