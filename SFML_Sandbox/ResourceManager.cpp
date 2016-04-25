#include "ResourceManager.h"
#include "ResourceBase.h"
#include "SpriteResource.h"
#include "SpriteSheetResource.h"
#include "AnimationResource.h"
#include "Locator.h"
#include "../../json11/json11.hpp"


tResourceManager::tResourceManager():
    m_CurrentScope(0)
    , m_ReferenceCount(0)
{
}

tResourceManager::~tResourceManager()
{
    m_Resources.clear();
}

bool tResourceManager::LoadResources(const std::string & path)
{
    bool success = false;
    char* pFile = nullptr;

    success = ReadFileToBuffer(pFile, path);
    if (success)
    {
        json11::Json jsonParser;
        std::string err;
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

bool tResourceManager::ReadFileToBuffer(char*& pBuffer, const std::string& path)
{
    bool success = false;
    std::ifstream fileStream(path.c_str(), std::ios::binary | std::ios::ate);
    fileStream.seekg(0, std::ios_base::end);
    std::streamoff fileSize = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
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
        std::map<std::string, json11::Json> it = data["image"].object_items();
        std::string path = it["path"].string_value();
        int x = it["x"].int_value();
        int y = it["y"].int_value();
        int w = it["width"].int_value();
        int h = it["height"].int_value();
        tSpriteResource* pImage = new tSpriteResource(path, x, y, w, h);
        success = AddResource(it["tag"].string_value(), pImage);
    }
    return success;
}
bool tResourceManager::ReadAnimationResouce(const json11::Json& data)
{
    bool success = false;
    if (data["animation"].is_null() == false)
    {
        std::map<std::string, json11::Json> animation = data["animation"].object_items();
        std::string animationTag = animation["tag"].string_value();
        tAnimationResource* pAnimation = new tAnimationResource(animationTag);
        if (animation["frames"].is_array() == true)
        {
            std::vector<json11::Json>::const_iterator iFrames = animation["frames"].array_items().begin();
            for (; iFrames != animation["frames"].array_items().end(); ++iFrames)
            {
                std::map<std::string, json11::Json> it = (*iFrames)["image"].object_items();
                std::string path = it["path"].string_value();
                std::string tag = it["tag"].string_value();
                int x = it["x"].int_value();
                int y = it["y"].int_value();
                int w = it["width"].int_value();
                int h = it["height"].int_value();
                tSpriteResource* pFrame = new tSpriteResource(path, x, y, w, h);
                AddResource(tag, pFrame);
                pAnimation->AddFrame(pFrame);
            }
        }
        success = AddResource(animationTag, pAnimation);
    }
    return success;
}
bool tResourceManager::ReadSpriteSheetResource(const json11::Json& data)
{
    bool success = false;
    // Read sprite sheet references
    if (data["spritesheet"].is_null() == false)
    {
        std::map<std::string, json11::Json> it = data["spritesheet"].object_items();
        std::string path = it["path"].string_value();
        tSpriteSheetResource* pSpriteSheet = new tSpriteSheetResource(path);
        success = AddResource(path, pSpriteSheet);
    }
    return success;
}
bool tResourceManager::AddResource(const std::string& key, tBaseResource* pResource)
{
    bool success = false;
    std::pair<std::map<std::string, std::shared_ptr<tBaseResource> >::iterator, bool> it = m_Resources.insert(std::make_pair(key, pResource));
    success = it.second;
    if(success = false)
    {
        std::string err("Resource cannot be loaded:  Element already exists: ");
        err += key;
        tLocator::GetLogger().Log(err);
    }
    return success;
}

std::shared_ptr<tBaseResource> tResourceManager::GetResource(const std::string& key)
{
    std::shared_ptr<tBaseResource> xResource = nullptr;

    std::map<std::string, std::shared_ptr<tBaseResource> >::iterator it = m_Resources.find(key);
    if (it != m_Resources.end())
    {
        xResource = it->second;
        if (xResource->IsLoaded() == false && xResource->LoadResource() == false)
        {
            std::string err("Resource cannot be loaded:  LoadResource failed: ");
            err += key;
            tLocator::GetLogger().Log(err);
        }
    }
    else
    {
        std::string err("Resource cannot be loaded : Resource not found : ");
        err += key;
        tLocator::GetLogger().Log(err);
    }
    return xResource;
}

bool tResourceManager::LoadResourceFromTag(const std::string& tag)
{
    bool success = false;
    std::map<std::string, std::shared_ptr<tBaseResource> >::iterator it = m_Resources.find(tag);
    if (it != m_Resources.end())
    {
        success = it->second->LoadResource();
    }
    return success;
}

void tResourceManager::update()
{
    std::map<std::string, std::shared_ptr<tBaseResource> >::iterator it = m_Resources.begin();
    while (it != m_Resources.end())
    {
        if (it->second->IsLoaded())
        {
            it->second->update();
        }
        ++it;
    }
}

void tResourceManager::Draw(sf::RenderWindow* pWindow)
{
    std::map<std::string, std::shared_ptr<tBaseResource> >::iterator it = m_Resources.begin();
    while (it != m_Resources.end())
    {
        //TODO: FIX THIS MAN.
        if (it->second->Type() == tBaseResource::ert_Animation && it->second->IsLoaded())
        {
            it->second->Draw(pWindow);
        }
        ++it;
    }
}