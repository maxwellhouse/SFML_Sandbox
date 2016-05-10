#pragma once
//Forward declares
class tGameEngine;

class tState
{
public:
    tState(tGameEngine* pGame) : m_pGameEngine(pGame) {};
    virtual void Draw(const float timeStep) = 0;
    virtual void Update(const float timeStep) = 0;
    virtual void HandleInput() = 0;

public:
    tGameEngine* m_pGameEngine;

private:
    tState() {};
};
