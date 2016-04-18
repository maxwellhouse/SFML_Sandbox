#pragma once
#include "SingletonTemplate.hpp"
#include <map>

//Forward declares
class tBaseResource;
namespace sf {
    class RenderWindow;
}
namespace json11
{
    class Json;
}
class tResourceManager : public tSingleton<tResourceManager>
{
public:
    tResourceManager();
    ~tResourceManager();

    tBaseResource* GetResource(const std::string& key);
    bool LoadResources(const std::string& path);
    bool LoadResourceFromTag(const std::string& tag);

    void update();
    void Draw(sf::RenderWindow*  pWindow);
    //void SetScope(unsigned int scope);
protected:
    unsigned int m_CurrentScope;
    unsigned int m_ReferenceCount;
    std::map<std::string, tBaseResource*> m_Resources;

private:
    bool ReadFileToBuffer(char*& pBuffer, const std::string& path);
    bool ParseJsonData(const json11::Json& jsonData);
    bool AddResource(const std::string& key, tBaseResource* pResource);
    bool ReadSpriteResource(const json11::Json& data);
    bool ReadSpriteSheetResource(const json11::Json& data);
    bool ReadAnimationResouce(const json11::Json& data);
};