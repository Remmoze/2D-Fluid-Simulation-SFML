#pragma once

class Grid
{
private:
	int width;
	int height;
	int tileSize;
	int* values;

public:
	Grid(int width, int height, int tileSize);

	int Get(int x, int y);
};

