#include <SFML/Graphics.hpp>
#include "DrawableGrid.h"
#include "MouseInput.h"

#include <iostream>

#define tile_width 50
#define tile_height 50
#define tile_size 10

int main()
{
    sf::RenderWindow window(sf::VideoMode(tile_width*tile_size, tile_height* tile_size), "Fluid simulation");
    window.setFramerateLimit(60);

    sf::Clock Clock;
    sf::Clock FpsClock;

    DrawableGrid grid(tile_width, tile_height, tile_size);
    MouseInput mouseInput(&grid);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(mouseInput.IsMouseEvent(event)) {
                mouseInput.HandleEvent(event);
            }
            if(event.type == sf::Event::Closed)
                window.close();
        }

        auto ElapsedTime = Clock.getElapsedTime(); //fixed time step
        auto fps = 1.f / ElapsedTime.asSeconds();
        Clock.restart();

        if(FpsClock.getElapsedTime().asMilliseconds() > 1000) {
            window.setTitle(std::to_string(fps));
            FpsClock.restart();
        }

        

        window.clear();
        window.draw(grid);
        window.display();
    }

    return 0;
}