#pragma once
#include "Commands.h"

// Forward declares
namespace sf
{
    class Window;
}
class tInputManager
{
public:
    tInputManager();

    tCommand* handleInput(sf::Window* pWindow);
private:
    tCommand* m_ButtonShoot;
    tCommand* m_ButtonPause;
    tCommand* m_ButtonLeft;
    tCommand* m_ButtonRight;
    tCommand* m_ButtonUp;
    tCommand* m_ButtonDown;
};