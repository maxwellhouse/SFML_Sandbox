#include "ResourceManager.h"
#include "ResourceBase.h"
#include "SpriteResource.h"
#include "SpriteSheetResource.h"
#include "AnimationResource.h"
#include "Locator.h"
#include "../../json11/json11.hpp"

using namespace std;

tResourceManager::~tResourceManager()
{
    m_Resources.clear();
}

bool tResourceManager::LoadResources(const string & path)
{
    bool success = false;
    char* pFile = nullptr;

    success = ReadFileToBuffer(pFile, path);
    if (success)
    {
        json11::Json jsonParser;
        string err;
        json11::Json jsonData = jsonParser.parse(pFile, err);
        if (err != "")
        {
            tLocator::GetLogger().Log(err);
            success = false;
        }
        else
        {
            success = ParseJsonData(jsonData);
        }
    }

    if(pFile)
        delete pFile;
    return success;
}

bool tResourceManager::ReadFileToBuffer(char*& pBuffer, const string& path)
{
    bool success = false;
    ifstream fileStream(path.c_str(), ios::binary | ios::ate);
    fileStream.seekg(0, ios_base::end);
    streamoff fileSize = fileStream.tellg();
    fileStream.seekg(0, ios::beg);
    if (fileSize > 0)
    {
        pBuffer = new char[static_cast<unsigned int>(fileSize+1)];
        fileStream.read(pBuffer, fileSize);
        pBuffer[fileSize] = '\0';
        success = true;
    }
    else
    {
        success = false;
    }
    fileStream.close();
    return success;
}

bool tResourceManager::ParseJsonData(const json11::Json& jsonData)
{
    bool success = false;
    // Read image references
    ReadSpriteResource(jsonData);
    // Read sprite sheet reference
    ReadSpriteSheetResource(jsonData);
    // Read sound references
    // Read animation references
    ReadAnimationResouce(jsonData);

    return success;
}
bool tResourceManager::ReadSpriteResource(const json11::Json& data)
{
    bool success = false;
    // Read image references
    if (data["image"].is_null() == false)
    {
        map<string, json11::Json> it = data["image"].object_items();
        string path = it["path"].string_value();
        int x = it["x"].int_value();
        int y = it["y"].int_value();
        int w = it["width"].int_value();
        int h = it["height"].int_value();
        tSpriteResource* pImage = new tSpriteResource(path, x, y, w, h);
        success = AddResource(it["gameStates"].array_items(), it["tag"].string_value(), pImage);
    }
    return success;
}
bool tResourceManager::ReadAnimationResouce(const json11::Json& data)
{
    bool success = false;
    if (data["animation"].is_null() == false)
    {
        map<string, json11::Json> animation = data["animation"].object_items();
        string animationTag = animation["tag"].string_value();
        int frameTime = animation["frameTime"].int_value();
        tAnimationResource* pAnimation = new tAnimationResource(animationTag, sf::milliseconds(frameTime));
        if (animation["frames"].is_array() == true)
        {
            vector<json11::Json>::const_iterator iFrames = animation["frames"].array_items().begin();
            for (; iFrames != animation["frames"].array_items().end(); ++iFrames)
            {
                map<string, json11::Json> it = (*iFrames)["image"].object_items();
                string path = it["path"].string_value();
                string tag = it["tag"].string_value();
                int x = it["x"].int_value();
                int y = it["y"].int_value();
                int w = it["width"].int_value();
                int h = it["height"].int_value();
                tSpriteResource* pFrame = new tSpriteResource(path, x, y, w, h);
                AddResource(animation["gameStates"].array_items(), tag, pFrame);
                pAnimation->AddFrame(pFrame);
            }
        }
        success = AddResource(animation["gameStates"].array_items(), animationTag, pAnimation);
    }
    return success;
}
bool tResourceManager::AddResource(const vector<json11::Json>& gameStates, const std::string& key, tBaseResource* pResource)
{
    bool success = false;
    vector<json11::Json>::const_iterator iStates = gameStates.begin();
    for (; iStates != gameStates.end(); ++iStates)
    {
        success = AddResource(static_cast<tState::eGameState>(iStates->int_value()), key, pResource);
    }
    return success;
}
bool tResourceManager::ReadSpriteSheetResource(const json11::Json& data)
{
    bool success = false;
    // Read sprite sheet references
    if (data["spritesheet"].is_null() == false)
    {
        map<string, json11::Json> it = data["spritesheet"].object_items();
        string path = it["path"].string_value();
        tSpriteSheetResource* pSpriteSheet = new tSpriteSheetResource(path);
        success = AddResource(it["gameStates"].array_items(), path, pSpriteSheet);
    }
    return success;
}
bool tResourceManager::AddResource(const tState::eGameState state, const string& key, tBaseResource* pResource)
{
    bool success = false;
    pair<map<string, shared_ptr<tBaseResource> >::iterator, bool> it = m_Resources[state].insert(make_pair(key, pResource));
    success = it.second;
    if(success = false)
    {
        string err("Resource cannot be loaded:  Element already exists: ");
        err += key;
        tLocator::GetLogger().Log(err);
    }
    return success;
}

shared_ptr<tBaseResource> tResourceManager::GetResource(const string& key)
{
    shared_ptr<tBaseResource> xResource = nullptr;
    map<tState::eGameState, map<string, shared_ptr<tBaseResource> > >::iterator stateIter = m_Resources.find(m_CurrentState);
    if (stateIter != m_Resources.end())
    {
        map<string, shared_ptr<tBaseResource> >::iterator keyIter = stateIter->second.find(key);
        if (keyIter != stateIter->second.end())
        {
            xResource = keyIter->second;
            if (xResource->IsLoaded() == false && xResource->LoadResource() == false)
            {
                string err("Resource cannot be loaded:  LoadResource failed: ");
                err += key;
                tLocator::GetLogger().Log(err);
            }
        }
    }

    if(xResource == nullptr)
    {
        string err("Resource cannot be loaded : Resource not found : ");
        err += key;
        tLocator::GetLogger().Log(err);
    }
    return xResource;
}

bool tResourceManager::LoadStateResources(const tState::eGameState state)
{
    bool success = false;
    map<tState::eGameState, map<string, shared_ptr<tBaseResource> > >::iterator stateIter = m_Resources.find(state);
    if (stateIter != m_Resources.end())
    {
        map<string, shared_ptr<tBaseResource> >::iterator keyIter = stateIter->second.begin();
        while (keyIter != stateIter->second.end())
        {
            success = keyIter->second->LoadResource();
            ++keyIter;
        }
    }
    if (success == false)
    {
        string err("Resource cannot be loaded : State not found : ");
        tLocator::GetLogger().Log(err);
    }
    m_CurrentState = state;
    return success;
}
