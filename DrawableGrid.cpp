#include "DrawableGrid.h"

DrawableGrid::DrawableGrid(int width, int height, int tileSize = 10) : Grid::Grid(width, height, tileSize) {
	gridLines = sf::VertexArray(sf::Lines, (width + 1) + (height + 1));
	squares = sf::VertexArray(sf::Quads, width * height * 4);

	for(int i = 0; i < width + 1; i++) {
		gridLines.append(sf::Vector2f(i * tileSize, 0));
		gridLines.append(sf::Vector2f(i * tileSize, height * tileSize));
	}

	for(int i = 0; i < height + 1; i++) {
		gridLines.append(sf::Vector2f(0, i * tileSize));
		gridLines.append(sf::Vector2f(width * tileSize, i * tileSize));
	}
}

void DrawableGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(squares, states);
	target.draw(gridLines, states);
}