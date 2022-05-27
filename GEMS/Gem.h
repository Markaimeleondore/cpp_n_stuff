#pragma once
#include <SFML/Graphics.hpp>

class Gem
{
	int x, y;
	int size = 54;
public:
	sf::RectangleShape * rect;
	int match_counter = 0;
	int x_position() { return rect->getPosition().x / size; }
	int y_position() { return rect->getPosition().y / size; }
};


