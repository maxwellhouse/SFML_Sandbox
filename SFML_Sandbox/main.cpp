#include "GameEngine.h"
#include <memory>
#include <thread>

int main()
{
    bool debug = true;
    std::shared_ptr<tGameEngine> xGame(new tGameEngine(debug));
    xGame->Initialize(1024, 768);
    xGame->Start();
    //std::thread gameThread(&tGameEngine::Start, tGameEngine::Instance());

    //gameThread.join();

    return 0;
}