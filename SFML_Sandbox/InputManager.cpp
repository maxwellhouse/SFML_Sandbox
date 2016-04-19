#include "InputManager.h"
#include "Commands.h"
#include <SFML/Window.hpp>

tInputManager::tInputManager()
{
    m_ButtonShoot = new tShootCommand();
    m_ButtonDown = new tMoveDownCommand();
    m_ButtonLeft = new tMoveLeftCommand();
    m_ButtonPause = new tPauseCommand();
    m_ButtonRight = new tMoveRightCommand();
    m_ButtonUp = new tMoveUpCommand();
}

tCommand* tInputManager::handleInput(sf::Window* pWindow)
{
    sf::Event event;
    while (pWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            pWindow->close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
                return m_ButtonShoot;
            else if (event.key.code == sf::Keyboard::Left)
                return m_ButtonLeft;
            else if (event.key.code == sf::Keyboard::Right)
                return m_ButtonRight;
            else if (event.key.code == sf::Keyboard::Up)
                return m_ButtonUp;
            else if (event.key.code == sf::Keyboard::Down)
                return m_ButtonDown;
            else if (event.key.code == sf::Keyboard::P)
                return m_ButtonPause;
        }
    }
    return nullptr;
}
