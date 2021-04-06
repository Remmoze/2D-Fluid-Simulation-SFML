#include "Grid.h"

Grid::Grid(int width, int height, int tileSize = 10) {
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;

	this->values = new int[width * height];
}

int Grid::Get(int x, int y) {
	return this->values[y * width + x];
}


