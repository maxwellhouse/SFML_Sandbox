#include "InputManager.h"
#include "Commands.h"
#include "SafeDelete.hpp"
#include <SFML/Window.hpp>

tInputManager::tInputManager()
{
    m_ButtonShoot = new tShootCommand();
    m_ButtonDown = new tMoveDownCommand();
    m_ButtonLeft = new tMoveLeftCommand();
    m_ButtonPause = new tPauseCommand();
    m_ButtonRight = new tMoveRightCommand();
    m_ButtonUp = new tMoveUpCommand();
    m_NoOperation = new tCommand();
}

tInputManager::~tInputManager()
{
    SafeDelete(m_ButtonDown);
    SafeDelete(m_ButtonLeft);
    SafeDelete(m_ButtonPause);
    SafeDelete(m_ButtonRight);
    SafeDelete(m_ButtonShoot);
    SafeDelete(m_ButtonUp);
    SafeDelete(m_NoOperation);
}

tCommand* tInputManager::handleInput(std::shared_ptr<sf::Window> xWindow)
{
    sf::Event event;
    while (xWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            xWindow->close();
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
    return m_NoOperation;
}
