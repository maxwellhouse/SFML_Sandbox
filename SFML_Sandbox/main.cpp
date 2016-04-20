#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "ResourceManager.h"
#include "AnimationResource.h"
#include "Logger.h"
#include "Locator.h"
#include "InputManager.h"
#include "Character.h"

#define MS_PER_UPDATE 16
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

int main()
{
    tLogger log(true);
    tLocator::InitializeLogger();
    tLocator::ProvideLogger(&log);
    tResourceManager* pResourceManager = tResourceManager::Instance();
    pResourceManager->LoadResources("../resources/resource.json");
    std::shared_ptr<tInputManager> xInputManager = std::make_shared<tInputManager>();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test");
    sf::Clock clock;
    sf::Time lag;
    sf::Time elapsed = clock.restart();

    pResourceManager->LoadResourceFromTag("spaceship_boost");
    std::shared_ptr<tCharacter> xPlayer = std::make_shared<tCharacter>(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 100, pResourceManager->GetResource("spaceship_boost"));
    while (true)
    {
        elapsed = clock.restart();
        lag += elapsed;

        tCommand* pCommand = xInputManager->handleInput(&window);
        pCommand->execute(xPlayer);

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