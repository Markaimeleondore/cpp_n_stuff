#pragma once
#include <iostream>
#include <utility>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Gem : public sf::RectangleShape
{
public:
	float x, y;
	int	match_counter;
	Gem(float _x, float _y) : x(_x), y(_y), match_counter(0)
	{
		this->setPosition(_x, _y);
		this->setSize({42,42});
		this->setOrigin(24, 24);
	}
	void swap(Gem& instance) { std::swap(x, instance.x); std::swap(y, instance.y); }

	bool operator==(Gem& instance) { return this->getFillColor() == instance.getFillColor(); }
	
};