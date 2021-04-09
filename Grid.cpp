#include "Grid.h"
#include <algorithm>

Grid::Grid(int width, int height, int tileSize = 10) {
	this->width = width + 2;
	this->height = height + 2;
	this->tileSize = tileSize;

	this->values = new int[this->width * this->height];
}

int Grid::Get(int x, int y) {
	if(!this->IsValidPosition(x, y)) {
		return -1;
	}
	return this->values[y * this->width + x];
}

void Grid::Set(int x, int y, int value) {
	if(!this->IsValidPosition(x, y)) {
		return;
	}
	this->values[y * this->width + x] = value;
}

void Grid::Clear(int value) {
	std::fill(this->values, this->values + this->width * this->height, value);
}

bool Grid::IsValidPosition(int x, int y) {
	return x >= 1 && y >= 1 && x < this->width-1 && y < this->height-1;
}