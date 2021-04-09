#include "DrawableGrid.h"
#include <iostream>

#define tileDefaultColor sf::Color(0, 0, 0, 255)
#define tileEdgeColor sf::Color(255, 0, 0, 255)
#define lineDefaultColor sf::Color(255, 255, 255, 100)

sf::Vertex CreateTile(int x, int y, int tileSize, bool edge = false) {
	return sf::Vertex(sf::Vector2f(x * tileSize, y * tileSize), edge ? tileEdgeColor : tileDefaultColor);
}

sf::Vertex CreateLine(int x, int y, int tileSize) {
	return sf::Vertex(sf::Vector2f(x * tileSize, y * tileSize), lineDefaultColor);
}

DrawableGrid::DrawableGrid(int width, int height, int tileSize = 10) : Grid::Grid(width, height, tileSize) {
	width = this->width;
	height = this->height;
	gridLines = sf::VertexArray(sf::Lines, ((width + height + 2) * 2));
	squares = sf::VertexArray(sf::Quads, width * height * 4);

	
	for(int i = 0; i < width + 1; i++) {
		auto index = i * 2;
		gridLines[index++] = CreateLine(i, 0, tileSize);
		gridLines[index++] = CreateLine(i, height, tileSize);
	}

	for(int i = 0; i < height + 1; i++) {
		auto index = (width + 1 + i) * 2;
		gridLines[index++] = CreateLine(0, i, tileSize);
		gridLines[index++] = CreateLine(width, i, tileSize);
	}

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			auto index = (y * height + x) * 4;
			bool IsEdge = x == 0 || y == 0 || x == this->width-1 || y == this->height-1;
			if(IsEdge)
				std::cout << x << " " << y << std::endl;
			squares[index++] = CreateTile(x + 0, y + 0, tileSize, IsEdge);
			squares[index++] = CreateTile(x + 1, y + 0, tileSize, IsEdge);
			squares[index++] = CreateTile(x + 1, y + 1, tileSize, IsEdge);
			squares[index++] = CreateTile(x + 0, y + 1, tileSize, IsEdge);
		}
	}
}

void DrawableGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(squares, states);
	target.draw(gridLines, states);
}

void DrawableGrid::Set(int x, int y, int value) {
	if(!this->IsValidPosition(x, y)) {
		return;
	}
	Grid::Set(x, y, value);
	for(int i = 0; i < 4; i++) {
		squares[(y * this->width + x) * 4 + i].color = sf::Color(value, value, value);
	}
}

void DrawableGrid::Clear(int value) {
	Grid::Clear(value);
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			bool IsEdge = x == 0 || y == 0 || x == this->width - 1 || y == this->height - 1;
			auto index = (y * height + x) * 4;
			squares[index++].color = IsEdge ? tileEdgeColor : tileDefaultColor;
			squares[index++].color = IsEdge ? tileEdgeColor : tileDefaultColor;
			squares[index++].color = IsEdge ? tileEdgeColor : tileDefaultColor;
			squares[index++].color = IsEdge ? tileEdgeColor : tileDefaultColor;
		}
	}
}