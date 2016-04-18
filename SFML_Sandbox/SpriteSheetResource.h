#pragma once
#include "ResourceBase.h"

//Forward declare
namespace sf
{
    class Texture;
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
    bool update();

private:
    sf::Texture* m_pTexture;
};
