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
    ~tInputManager();

    tCommand* handleInput(std::shared_ptr<sf::Window> xWindow);
private:
    tCommand* m_ButtonShoot;
    tCommand* m_ButtonPause;
    tCommand* m_ButtonLeft;
    tCommand* m_ButtonRight;
    tCommand* m_ButtonUp;
    tCommand* m_ButtonDown;
    tCommand* m_NoOperation;
};