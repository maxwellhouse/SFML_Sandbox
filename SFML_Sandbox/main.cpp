#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "ResourceManager.h"
#include "AnimationResource.h"
#include "Logger.h"
#include "Locator.h"
#include "InputManager.h"

#define MS_PER_UPDATE 16

int main()
{
    tLogger log(true);
    tLocator::InitializeLogger();
    tLocator::ProvideLogger(&log);
    tResourceManager* pResourceManager = tResourceManager::Instance();
    pResourceManager->LoadResources("../resources/resource.json");
    std::shared_ptr<tInputManager> xInputManager = std::make_shared<tInputManager>();


    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Test");
    sf::Clock clock;
    sf::Time lag;
    sf::Time elapsed = clock.restart();

    pResourceManager->LoadResourceFromTag("spaceship_boost");
    while (true)
    {
        elapsed = clock.restart();
        lag += elapsed;

        tCommand* pCommand = xInputManager->handleInput(&window);
        pCommand->execute(pPlayer);

        while (lag.asMilliseconds() >= MS_PER_UPDATE)
        {
            pResourceManager->update();
            lag -= sf::milliseconds(MS_PER_UPDATE);
        }
        //pResourceManager->update();
        pResourceManager->Draw(&window);
        window.display();
    }

    return 0;
}