#pragma once
#include <string>

//Foward declares
namespace sf {
    class RenderWindow;
}
class tBaseResource
{
public:
    enum eResourceType
    {
        ert_Sprite,
        ert_SpriteSheet,
        ert_Sound,
        ert_Animation,
        ert_None
    };
    tBaseResource(const std::string& path, const eResourceType type = ert_None);
    virtual ~tBaseResource();
    eResourceType Type() const;
    std::string Path() const;
    bool IsLoaded() const;
    void SetLoaded(bool loaded);
public:
    virtual bool LoadResource() = 0;
    virtual void UnloadResource() = 0;
    virtual bool update() = 0;
    virtual void Draw(sf::RenderWindow* pWindow) {};
private:
    std::string m_Path;
    eResourceType m_Type;
    bool m_IsLoaded;
};