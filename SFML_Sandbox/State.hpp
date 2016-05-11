#pragma once
#include <memory>
//Forward declares
class tGameEngine;

class tState
{
public:
    tState(std::shared_ptr<tGameEngine> xGame) : m_xGameEngine(xGame) {};
    virtual void Draw(const int timeStep) = 0;
    virtual void Update(const int timeStep) = 0;
    virtual void HandleInput() = 0;

public:
    std::shared_ptr<tGameEngine> m_xGameEngine;
public:
    enum eGameState {
        eGS_Start,
        eGS_Menu,
        eGS_Play,
        eGS_Pause,
    };
private:
    tState() {};
};
