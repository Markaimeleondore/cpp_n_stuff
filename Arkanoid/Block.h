#pragma once
#include "Rectangle_shaped_objects.h"
constexpr float block_width{ 60.f }, block_height{ 20.f };

class Block : public Rectange_shaped_objects
{
public:
	bool destroyed = false;
	Block(int x, int y, float height_of_block, float width_of_block) : Rectange_shaped_objects(x, y, block_height, block_width, sf::Color::Yellow) {};

};
