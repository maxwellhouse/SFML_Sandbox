#pragma once
#include <memory>
// Forward declares
class tActor;

class tCommand
{
public:
    virtual ~tCommand() {}
    virtual void execute(const std::shared_ptr<tActor>& xActor) {};
};

class tShootCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};

class tMoveLeftCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};

class tMoveRightCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};

class tMoveUpCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};

class tMoveDownCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};
class tPauseCommand : public tCommand
{
    virtual void execute(const std::shared_ptr<tActor>& xActor);
};