#pragma once
#include "Gem.h"
#include <iostream>
#include <utility>
#include <algorithm>

class Frame
{
public:
	Gem *grid[11][11];
	bool swap_flag;
	int click_counter;
	void fulfill();
	void check_matches();
};