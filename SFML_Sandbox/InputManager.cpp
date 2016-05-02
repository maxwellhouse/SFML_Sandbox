#include "InputManager.h"
#include "Commands.h"
#include "SafeDelete.hpp"
#include "Character.h"
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

void tInputManager::handleInput(sf::Window& window, const std::shared_ptr<tCharacter>& xCharacter)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
                m_ButtonShoot->execute(xCharacter);
            else if (event.key.code == sf::Keyboard::Left)
                m_ButtonLeft->execute(xCharacter);
            else if (event.key.code == sf::Keyboard::Right)
                m_ButtonRight->execute(xCharacter);
            else if (event.key.code == sf::Keyboard::Up)
                m_ButtonUp->execute(xCharacter);
            else if (event.key.code == sf::Keyboard::Down)
                m_ButtonDown->execute(xCharacter);
            else if (event.key.code == sf::Keyboard::P)
                m_ButtonPause->execute(xCharacter);
        }
    }
}
