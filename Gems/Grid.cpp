#include "Grid.h"
#include "Gem.h"
#include <iostream>
#include <utility>
#include <algorithm>
void Grid::fulfill_grid()
{
	for (int i = 0; i < size_height; i++)
	{
		for (int j = 0; j < size_width; j++)
		{
			grid.push_back(new Gem(make_pair(i, j), rand() % 3);
		}
	}
}

void Grid::update()
{
}
