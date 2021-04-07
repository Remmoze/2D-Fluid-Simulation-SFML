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

        window.clear();
        window.draw(grid);
        window.display();
    }

    return 0;
}