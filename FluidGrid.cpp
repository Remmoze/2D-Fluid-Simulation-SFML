#include "FluidGrid.h"

FluidGrid::FluidGrid(int width, int height, int tileSize) : DrawableGrid(width, height, tileSize) {};

void FluidGrid::Update(float deltaTime) {
	for(int y = 0; y < this->height; y++) {
		for(int x = 0; x < this->width; x++) {
			auto value = this->Get(x, y);
			if(value > 0) {
				this->Set(x, y, value - 2 > 0 ? value - 2 : 0);
			}
		}
	}
}