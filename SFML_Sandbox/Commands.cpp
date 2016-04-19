#include "Commands.h"

void tShootCommand::execute(tActor * pActor)
{
    pActor->shoot();
}

void tMoveLeftCommand::execute(tActor * pActor)
{
    pActor->moveLeft();
}

void tMoveRightCommand::execute(tActor * pActor)
{
    pActor->moveRight();
}

void tMoveUpCommand::execute(tActor * pActor)
{
    pActor->moveUp();
}

void tMoveDownCommand::execute(tActor * pActor)
{
    pActor->moveDown();
}

void tPauseCommand::execute(tActor * pActor)
{
    // I dunno figure it out later.
    // Use state manager or something.
}
