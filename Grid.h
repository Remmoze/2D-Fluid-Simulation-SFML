#pragma once

class Grid
{
protected:
	int* values;

public:

	Grid(int width, int height, int tileSize);

	int Get(int x, int y);
	void Set(int x, int y, int value);
	void Clear();

	int width;
	int height;
	int tileSize;
};

