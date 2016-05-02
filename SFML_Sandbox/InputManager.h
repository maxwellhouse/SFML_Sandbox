#pragma once
#include "Commands.h"

// Forward declares
class tCharacter;
namespace sf
{
    class Window;
}
class tInputManager
{
public:
    tInputManager();
    ~tInputManager();

    void handleInput(sf::Window& window, const std::shared_ptr<tCharacter>& xCharacter);
private:
    tCommand* m_ButtonShoot;
    tCommand* m_ButtonPause;
    tCommand* m_ButtonLeft;
    tCommand* m_ButtonRight;
    tCommand* m_ButtonUp;
    tCommand* m_ButtonDown;
    tCommand* m_NoOperation;
};