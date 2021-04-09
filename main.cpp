#include <SFML/Graphics.hpp>
#include "FluidGrid.h"
#include "MouseInput.h"

#include <iostream>

#define tile_width 50
#define tile_height 50
#define tile_size 10

int main()
{
    sf::RenderWindow window(sf::VideoMode((tile_width + 2) *tile_size, (tile_height+2)* tile_size), "Fluid simulation");
    window.setFramerateLimit(60);

    sf::Clock Clock;
    sf::Clock FpsClock;

    FluidGrid grid(tile_width, tile_height, tile_size);
    MouseInput mouseInput(&grid);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(mouseInput.IsMouseEvent(event)) {
                mouseInput.HandleEvent(event);
            }
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Q)
                    grid.Clear(255);
            }
            if(event.type == sf::Event::Closed)
                window.close();
        }

        auto ElapsedTime = Clock.getElapsedTime().asMilliseconds(); //fixed time step
        Clock.restart();

        grid.Update(ElapsedTime);

        if(FpsClock.getElapsedTime().asMilliseconds() > 1000) {
            window.setTitle(std::to_string(1000.f / ElapsedTime));
            FpsClock.restart();
        }

        window.clear();
        window.draw(grid);
        window.display();
    }

    return 0;
}