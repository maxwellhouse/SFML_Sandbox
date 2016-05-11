#include "GameEngine.h"
#include "ResourceManager.h"
#include "AnimationResource.h"
#include "Logger.h"
#include "Locator.h"
#include "InputManager.h"
#include "Character.h"
#include "State.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

std::shared_ptr<tResourceManager> tGameEngine::m_xResourceManager = std::make_shared<tResourceManager>();

tGameEngine::tGameEngine() :
      m_WindowHeight(0)
    , m_WindowWidth(0)
{

}

tGameEngine::tGameEngine(bool debug) :
      m_WindowHeight(768)
    , m_WindowWidth(1024)
{
    tLogger log(debug);
    tLocator::InitializeLogger();
    tLocator::ProvideLogger(&log);
}

tGameEngine::~tGameEngine()
{
    while (m_States.empty() == false)
    {
        PopState();
    }
}

bool tGameEngine::Initialize(const int width, const int height)
{
    bool success = false;
    
    m_WindowHeight = height;
    m_WindowWidth = width;

    m_xWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_WindowWidth, m_WindowHeight), "Test");

    m_xResourceManager->LoadResources("../resources/resource.json");

    m_xInputManager = std::make_shared<tInputManager>();
    m_xPlayer = std::make_shared<tCharacter>(0
                                           , 0
                                           , 100
                                           , 10
                                           , m_xResourceManager->GetResource("spaceship_boost")
                                           , shared_from_this());

    m_Characters.push_back(m_xPlayer);
    return success;
}

void tGameEngine::Start()
{
    sf::Clock clock;
    sf::Time lag;
    sf::Time elapsed = clock.restart();

    while (true)
    {
        elapsed = clock.restart();
        lag += elapsed;

        m_xInputManager->handleInput(*m_xWindow, m_xPlayer);

        while (lag.asMilliseconds() >= m_MSPerUpdate)
        {
            lag -= sf::milliseconds(m_MSPerUpdate);
        }

        tState* pCurState = PeekState();
        if (pCurState != nullptr)
        {
            pCurState->HandleInput();
            pCurState->Update(lag.asMilliseconds());
            pCurState->Draw(lag.asMilliseconds());
            m_xWindow->clear();
        }
        m_xWindow->display();
    }

}

void tGameEngine::PushState(tState * pState)
{
    m_States.push(pState);
}

void tGameEngine::PopState()
{
    delete m_States.top();
    m_States.pop();
}

void tGameEngine::ChangeState(tState * pState)
{
    if (m_States.empty() == false)
    {
        PopState();
    }
    PushState(pState);
}

tState * tGameEngine::PeekState()
{
    if (m_States.empty())
    {
        return nullptr;
    }
    return m_States.top();
}
