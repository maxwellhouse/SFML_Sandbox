#pragma once
#include <vector>
#include <memory>

//Forward declares
class tBaseResource;

class tActor
{
public:
    tActor();
    tActor(const int x, const int y, const std::shared_ptr<tBaseResource>& xResource);
    virtual ~tActor();
    virtual bool moveLeft() = 0;
    virtual bool moveRight() = 0;
    virtual bool moveUp() = 0;
    virtual bool moveDown() = 0;
    virtual bool shoot() = 0;

private:
    int m_XPos;
    int m_YPos;
    std::shared_ptr<tBaseResource> m_xResource;
    std::vector<tActor*> m_Projectiles;
};

