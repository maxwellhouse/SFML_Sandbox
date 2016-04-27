#pragma once
#include "SingletonTemplate.hpp"

#include <memory>

//Forward declares
class tCharacter;
class tInputManager;
class tResourceManager;

namespace sf {
    class RenderWindow;
}
class tGameEngine : public tSingleton<tGameEngine>
{
public:
    tGameEngine();
    ~tGameEngine() {};
    tGameEngine(bool debug);

    void Start();

    unsigned int CurrentWidth() const { return m_WindowWidth; }
    unsigned int CurrentHeight() const { return m_WindowHeight; }
    static unsigned int MaxBulletsPerActor() { return m_MaxBulletsPerActor; }

    // Manager accessors
    static std::shared_ptr<tResourceManager> ResourceManager(){ return m_xResourceManager; }

private:
    tGameEngine(const tGameEngine&) {};
    bool Initialize(const int width, const int height);

private:
    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;
    static const int m_MSPerUpdate = 16;
    static const int m_MaxBulletsPerActor = 100;

    // Managers
    std::shared_ptr<tInputManager> m_xInputManager;
    static std::shared_ptr<tResourceManager> m_xResourceManager;

    // Entities
    std::shared_ptr<tCharacter> m_xPlayer;

    // Window
    std::shared_ptr<sf::RenderWindow> m_xWindow;
};