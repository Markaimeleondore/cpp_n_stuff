#pragma once
#include <SFML/Graphics.hpp>
#include "Gem.h"
#include <vector>
class Bonus
{
protected:
	int x, y;
	virtual void choose_others(Gem grid[10][10]) = 0;
	std::vector<std::pair<int, int>> others;
public:
	void set_position(int _x, int _y) { this->x = _x; this->y = _y; }
	virtual void action(sf::RenderWindow& game, Gem grid[10][10]) = 0;
	
};

class Color_changer : public Bonus
{
protected:
	void choose_others(Gem grid[10][10]) override;
public:
	
	sf::Color this_color;
	void action(sf::RenderWindow& game, Gem grid[10][10]) override;
	
};

class Bomb : public Bonus
{
protected:
	void choose_others(Gem grid[10][10]) override;
public:
	void action(sf::RenderWindow& game, Gem grid[10][10]) override;
	
};