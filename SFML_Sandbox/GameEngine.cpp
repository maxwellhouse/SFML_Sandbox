#include "GameEngine.h"
#include "ResourceManager.h"
#include "AnimationResource.h"
#include "Logger.h"
#include "Locator.h"
#include "InputManager.h"
#include "Character.h"

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

bool tGameEngine::Initialize(const int width, const int height)
{
    bool success = false;
    
    m_WindowHeight = height;
    m_WindowWidth = width;

    m_xWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_WindowWidth, m_WindowHeight), "Test");

    m_xResourceManager->LoadResources("../resources/resource.json");

    m_xInputManager = std::make_shared<tInputManager>();
    m_xPlayer = std::make_shared<tCharacter>(m_WindowWidth / 2, m_WindowHeight / 2, 100, 10, m_xResourceManager->GetResource("spaceship_boost"));

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
        for (auto & xCharacter : m_Characters)
        {
            xCharacter->Update(lag.asMilliseconds());
            xCharacter->Draw(m_xWindow);
        }
        //pResourceManager->update();
        //pResourceManager->Draw(m_xWindow);
        m_xWindow->display();
    }

}