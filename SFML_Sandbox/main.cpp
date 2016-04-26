#include "GameEngine.h"

#include <thread>

int main()
{
    std::thread gameThread(&tGameEngine::Start, tGameEngine::Instance());

    gameThread.join();

    return 0;
}