#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableGrid.h"

class MouseInput
{
private:
	DrawableGrid* grid;

	bool LeftButtonPressed = false;

public:
	MouseInput(DrawableGrid* grid);

	void HandleEvent(sf::Event e);
	sf::Vector2i GetGridCoords(int x, int y);
	sf::Vector2i GetGridCoords(sf::Event e);

	void PlaceBlock(int x, int y, int value);
	void PlaceBlock(sf::Vector2i loc, int value);

	static bool IsMouseEvent(sf::Event e);

	
};

