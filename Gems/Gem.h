#pragma once
#include <iostream>
#include <utility>
#include <algorithm>

class Gem
{
	int size, colour, match_counter;
	std::pair<int, int> index_position;
public:
	Gem(std::pair<int, int> indexes, int _colour) : index_position(indexes), colour(_colour), size(50), match_counter(1) {};
	void add_match() { match_counter++; };
	void refresh_matches() { match_counter = 1; }
	int get_size() { return size; }
	void set_color(int colour_number) { colour = colour_number; }
	std::pair<int, int> get_position() { return index_position; }
	void change_position(std::pair<int, int> new_position) { index_position = new_position; }
	void swap_positions(Gem& another_one) {swap() }
};