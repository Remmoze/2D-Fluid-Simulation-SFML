#include "Grid.h"
#include <algorithm>

Grid::Grid(int width, int height, int tileSize = 10) {
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;

	this->values = new int[width * height];
}

int Grid::Get(int x, int y) {
	return this->values[y * width + x];
}

void Grid::Set(int x, int y, int value) {
	this->values[y * width + x] = value;
}

void Grid::Clear() {
	std::fill(this->values, this->values + width * height, 0);
}

