#include "GameEngine.h"

#include <thread>

int main()
{
    tGameEngine::Instance()->Initialize(1024, 768);
    tGameEngine::Instance()->Start();
    //std::thread gameThread(&tGameEngine::Start, tGameEngine::Instance());

    //gameThread.join();

    return 0;
}