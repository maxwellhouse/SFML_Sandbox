#pragma once
#include <memory>
#include <vector>
#include <stack>

//Forward declares
class tCharacter;
class tInputManager;
class tResourceManager;
class tState;

namespace sf {
    class RenderWindow;
}
class tGameEngine : public std::enable_shared_from_this<tGameEngine>
{
public:
    tGameEngine();
    ~tGameEngine();
    tGameEngine(bool debug);
    bool Initialize(const int width, const int height);

    void Start();

    // State managers
    void PushState(tState* pState);
    void PopState();
    void ChangeState(tState* pState);
    tState* PeekState();

    // Accessors
    std::shared_ptr<sf::RenderWindow> Window() { return m_xWindow; }
    unsigned int CurrentWidth() const { return m_WindowWidth; }
    unsigned int CurrentHeight() const { return m_WindowHeight; }
    static unsigned int MaxBulletsPerActor() { return m_MaxBulletsPerActor; }

    // Manager accessors
    static std::shared_ptr<tResourceManager> ResourceManager(){ return m_xResourceManager; }

private:
    tGameEngine(const tGameEngine&) {};

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
    std::vector<std::shared_ptr<tCharacter> > m_Characters;

    // States
    std::stack<tState*> m_States;

    // Window
    std::shared_ptr<sf::RenderWindow> m_xWindow;
};