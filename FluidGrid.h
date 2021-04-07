#pragma once
#include "DrawableGrid.h"

class FluidGrid: public DrawableGrid
{
public:
	FluidGrid(int width, int height, int tileSize);
	void Update(float deltaTime);
};

