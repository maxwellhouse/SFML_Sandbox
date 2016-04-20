#include "Commands.h"
#include "Actor.h"

void tShootCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->shoot();
}

void tMoveLeftCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->moveLeft();
}

void tMoveRightCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->moveRight();
}

void tMoveUpCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->moveUp();
}

void tMoveDownCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->moveDown();
}

void tPauseCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    // I dunno figure it out later.
    // Use state manager or something.
}
