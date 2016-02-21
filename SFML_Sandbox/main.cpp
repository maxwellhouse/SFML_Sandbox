#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Test");
    // run the program as long as the window is open
    unsigned int r = 255, g = 255, b = 255;
    int rotate = 0;
    sf::Texture image;
    sf::Sprite sprite;
    if (image.loadFromFile("../resources/sprites/Sprite-Soda.png") == true)
    {
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case sf::Keyboard::R:
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            if (r > 0) r-=10;
                        }
                        else
                        {
                            if (r < 255) r+=10;
                        }
                    }
                    break;
                    case sf::Keyboard::G:
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            if (g > 0) g-=10;
                        }
                        else
                        {
                            if (g < 255) g+=10;
                        }
                    }
                    break;
                    case sf::Keyboard::B:
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            if (b > 0) b-=10;
                        }
                        else
                        {
                            if (b < 255) b+=10;
                        }
                    }
                    break;
                    case sf::Keyboard::T:
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            if (rotate > 0) rotate -= 5;
                        }
                        else
                        {
                            if (rotate < 360) rotate += 5;
                        }
                    }
                    }
                }
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // Draw here
            sprite.setTexture(image);
            sprite.setColor(sf::Color(r, g, b));
            sprite.setRotation(rotate);
            window.draw(sprite);

            // end the current frame
            window.display();
        }
    }
    
    return 0;
}