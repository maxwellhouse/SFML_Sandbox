#pragma once
#include "StateManager.h"
#include <map>
#include <memory>

//Forward declares
class tBaseResource;
namespace sf {
    class RenderWindow;
}
namespace json11
{
    class Json;
}
class tResourceManager
{
public:
    tResourceManager();
    ~tResourceManager();

public:
    std::shared_ptr<tBaseResource> GetResource(const std::string& key);
    bool LoadResources(const std::string& path);
    bool LoadResourceFromTag(const std::string& tag);

protected:
    std::map<std::string, std::shared_ptr<tBaseResource> > m_Resources;

private:
    bool ReadFileToBuffer(char*& pBuffer, const std::string& path);
    bool ParseJsonData(const json11::Json& jsonData);
    bool AddResource(const std::string& key, tBaseResource* pResource);
    bool ReadSpriteResource(const json11::Json& data);
    bool ReadSpriteSheetResource(const json11::Json& data);
    bool ReadAnimationResouce(const json11::Json& data);
};