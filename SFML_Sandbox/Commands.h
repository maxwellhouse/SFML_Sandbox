#pragma once
#include <memory>
// Forward declares
class tEntity;

class tCommand
{
public:
    virtual ~tCommand() {}
    virtual void execute(const std::shared_ptr<tEntity>& xActor) {};
};

class tShootCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};

class tMoveLeftCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};

class tMoveRightCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};

class tMoveUpCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};

class tMoveDownCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};
class tPauseCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tEntity>& xActor);
};