#pragma once
#include <vector>
#include <memory>

//Forward declares
class tBaseResource;
namespace sf {
    class RenderWindow;
}
class tEntity
{
public:
    tEntity();
    tEntity(const int x, const int y, const int speed, const std::shared_ptr<tBaseResource>& xResource);
    virtual ~tEntity();
    virtual bool MoveLeft();
    virtual bool MoveRight();
    virtual bool MoveUp();
    virtual bool MoveDown();
    virtual bool Shoot() { return false; };

    virtual bool Update(const unsigned int lag) = 0;
    virtual void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow) = 0;

protected:
    unsigned int m_XPos;
    unsigned int m_YPos;
    int m_Speed;
    std::shared_ptr<tBaseResource> m_xResource;
};

