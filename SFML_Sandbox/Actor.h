#pragma once
#include <vector>
#include <memory>

//Forward declares
class tBaseResource;
namespace sf {
    class RenderWindow;
}
class tActor
{
public:
    tActor();
    tActor(const int x, const int y, const std::shared_ptr<tBaseResource>& xResource);
    virtual ~tActor();
    virtual bool MoveLeft() = 0;
    virtual bool MoveRight() = 0;
    virtual bool MoveUp() = 0;
    virtual bool MoveDown() = 0;
    virtual bool Shoot() = 0;

    virtual bool Update(const unsigned int lag) = 0;
    virtual void Draw(sf::RenderWindow* pWindow, const unsigned int lag) = 0;

protected:
    int m_XPos;
    int m_YPos;
    std::shared_ptr<tBaseResource> m_xResource;
};

