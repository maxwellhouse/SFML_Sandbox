#pragma once
#include "State.hpp"
#include <map>
#include <memory>
#include <vector>
#include <string>

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
    tResourceManager() : m_CurrentState(tState::eGS_Start) {};
    ~tResourceManager();

public:
    std::shared_ptr<tBaseResource> GetResource(const std::string& key);
    bool LoadResources(const std::string & path);
    bool LoadStateResources(const tState::eGameState state);

protected:
    std::map<tState::eGameState, std::map<std::string, std::shared_ptr<tBaseResource> > > m_Resources;

private:
    bool ReadFileToBuffer(char*& pBuffer, const std::string& path);
    bool ParseJsonData(const json11::Json& jsonData);
    bool AddResource(const tState::eGameState state, const std::string& key, tBaseResource* pResource);
    bool ReadSpriteResource(const json11::Json& data);
    bool ReadSpriteSheetResource(const json11::Json& data);
    bool ReadAnimationResouce(const json11::Json& data);
    bool AddResource(const std::vector<json11::Json>& gameStates, const std::string& key, tBaseResource* pResource);

private:
    tState::eGameState m_CurrentState;
};