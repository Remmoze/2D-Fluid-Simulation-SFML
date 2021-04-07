#include "Grid.h"
#include <algorithm>

Grid::Grid(int width, int height, int tileSize = 10) {
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;

	this->values = new int[width * height];
}

int Grid::Get(int x, int y) {
	if(!this->IsValidPosition(x, y)) {
		return -1;
	}
	return this->values[y * width + x];
}

void Grid::Set(int x, int y, int value) {
	if(!this->IsValidPosition(x, y)) {
		return;
	}
	this->values[y * width + x] = value;
}

void Grid::Clear() {
	std::fill(this->values, this->values + width * height, 0);
}

bool Grid::IsValidPosition(int x, int y) {
	return x >= 0 && y >= 0 && x < this->width&& y < this->height;
}