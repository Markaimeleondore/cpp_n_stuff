#pragma once
#include "Gem.h"
constexpr int field_size{ 8 };
constexpr int gem_size{ 54 };

class Field
{
	bool compare(sf::RectangleShape *instance1, sf::RectangleShape *instance2) { return instance1->getFillColor() == instance2->getFillColor(); }
	void repair_gems();
	void rebuild();
	void draw();
	void change_positions(int x_fs, int y_fs, int x_sc, int y_sc);
	void check_matches();
public:
	Gem grid[field_size + 2][field_size + 2];
	
	sf::RenderWindow game{ {740, 640}, "GEMS" };
	void fulfill();
	void update();
	void actions(int& click_counter, int& x_pressed, int& y_pressed);
	void drawAll();
};