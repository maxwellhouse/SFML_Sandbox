#pragma once

// Forward declares
class tActor;

class tCommand
{
public:
    virtual ~tCommand() {}
    virtual void execute(tActor* pActor) = 0;
};

class tShootCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};

class tMoveLeftCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};

class tMoveRightCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};

class tMoveUpCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};

class tMoveDownCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};
class tPauseCommand : public tCommand
{
    virtual void execute(tActor* pActor);
};