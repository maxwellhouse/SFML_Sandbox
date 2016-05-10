#pragma once
#include <vector>
#include <memory>

//Forward declares
class tBaseResource;
class tGameEngine;
namespace sf {
    class RenderWindow;
}
class tEntity
{
public:
    tEntity();
    tEntity(const int x
            , const int y
            , const int speed
            , const std::shared_ptr<tBaseResource>& xResource
            , const std::shared_ptr<tGameEngine>& xEngine);
    virtual ~tEntity();
    virtual bool MoveLeft();
    virtual bool MoveRight();
    virtual bool MoveUp();
    virtual bool MoveDown();
    virtual bool Shoot() { return false; };

    virtual bool Update(const unsigned int lag) = 0;
    virtual void Draw(const std::shared_ptr<sf::RenderWindow>& xWindow) = 0;

private:
    bool Move(const int x, const int y);
    bool OffsetMove(const int x, const int y);

protected:
    unsigned int m_XPos;
    unsigned int m_YPos;
    int m_Speed;
    std::shared_ptr<tBaseResource> m_xResource;
    std::shared_ptr<tGameEngine> m_xGameEngine;
};

