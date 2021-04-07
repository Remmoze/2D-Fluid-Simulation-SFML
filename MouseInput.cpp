#include "MouseInput.h"
#include <math.h>

MouseInput::MouseInput(DrawableGrid* grid) {
	this->grid = grid;
}

void MouseInput::HandleEvent(sf::Event e) {
	switch(e.type) {
		case sf::Event::MouseButtonPressed: {
			if(e.mouseButton.button == sf::Mouse::Left) {
				this->LeftButtonPressed = true;
				this->PlaceBlock(this->GetGridCoords(e), 255);
			}
		}; break;
		case sf::Event::MouseButtonReleased: {
			if(e.mouseButton.button == sf::Mouse::Left)
				this->LeftButtonPressed = false;
		}
		case sf::Event::MouseMoved: {
			if(this->LeftButtonPressed)
				this->PlaceBlock(this->GetGridCoords(e), 255);
		}

		default:
			break;
	}
}

void MouseInput::PlaceBlock(sf::Vector2i loc, int value) {
	this->PlaceBlock(loc.x, loc.y, value);
}

void MouseInput::PlaceBlock(int x, int y, int value) {
	this->grid->Set(x, y, value);
}

sf::Vector2i MouseInput::GetGridCoords(int x, int y) {
	int tileSize = this->grid->tileSize;
	return sf::Vector2i(floor(x / tileSize), floor(y / tileSize));
}

sf::Vector2i MouseInput::GetGridCoords(sf::Event e) {
	if(e.type == sf::Event::MouseMoved) {
		return this->GetGridCoords(e.mouseMove.x, e.mouseMove.y);
	}
	return this->GetGridCoords(e.mouseButton.x, e.mouseButton.y);
}

bool MouseInput::IsMouseEvent(sf::Event e) {
	return e.type == sf::Event::MouseButtonPressed || e.type == sf::Event::MouseButtonReleased || e.type == sf::Event::MouseMoved;
}