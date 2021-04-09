#include "FluidGrid.h"
#include <algorithm>

#define DiffusionFactor 0.5

FluidGrid::FluidGrid(int width, int height, int tileSize) : DrawableGrid(width, height, tileSize) {
	oldState = new int[this->width * this->height];
};

void FluidGrid::Update(float deltaTime) {

	std::copy(this->values, this->values + this->width * this->height, this->oldState);

	for(int y = 1; y < this->height-1; y++) {
		for(int x = 1; x < this->width-1; x++) {
			/*auto Sn = this->GetAverageOfNeighbours(this->values, x, y);
			auto Dc = this->Get(x, y);
			auto Dn = (Dc + DiffusionFactor * Sn) / (1 + DiffusionFactor);
			this->Set(x, y, Dn);*/
			auto value = this->Get(x, y);
			this->Set(x, y, value - 3 > 0 ? value - 3 : 0);

		}
	}
}