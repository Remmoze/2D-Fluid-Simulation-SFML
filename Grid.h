#pragma once

class Grid
{
protected:
	int* values;

	bool IsValidPosition(int x, int y);

public:

	Grid(int width, int height, int tileSize);

	int Get(int x, int y);
	void Set(int x, int y, int value);
	void Clear(int value = 0);

	int width;
	int height;
	int tileSize;
};

