#include "Commands.h"
#include "Entity.h"

void tShootCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    xActor->Shoot();
}

void tMoveLeftCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    xActor->MoveLeft();
}

void tMoveRightCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    xActor->MoveRight();
}

void tMoveUpCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    xActor->MoveUp();
}

void tMoveDownCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    xActor->MoveDown();
}

void tPauseCommand::execute(const std::shared_ptr<tEntity>& xActor)
{
    // I dunno figure it out later.
    // Use state manager or something.
}
