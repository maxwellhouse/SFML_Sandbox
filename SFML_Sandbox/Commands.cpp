#include "Commands.h"
#include "Actor.h"

void tShootCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->Shoot();
}

void tMoveLeftCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->MoveLeft();
}

void tMoveRightCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->MoveRight();
}

void tMoveUpCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->MoveUp();
}

void tMoveDownCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    xActor->MoveDown();
}

void tPauseCommand::execute(const std::shared_ptr<tActor>& xActor)
{
    // I dunno figure it out later.
    // Use state manager or something.
}
