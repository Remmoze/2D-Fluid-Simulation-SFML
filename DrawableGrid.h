#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Grid.h"

class DrawableGrid: public sf::Drawable, public Grid
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray squares;
	sf::VertexArray gridLines;

public:
	DrawableGrid(int width, int height, int tileSize);
	void Set(int x, int y, int value);
	void Clear(int value = 0);
};

