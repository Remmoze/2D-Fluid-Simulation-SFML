#pragma once
#include "DrawableGrid.h"

class FluidGrid: public DrawableGrid
{
private:
	int* oldState;


public:

	FluidGrid(int width, int height, int tileSize);
	void Update(float deltaTime);
};

