#pragma once
#include "Rectangle_shaped_objects.h"
constexpr float block_width{ 60.f }, block_height{ 20.f }, moving_block_velocity{ 5.f };
constexpr int windowWidth{ 1024 }, windowHeight{ 768 }, frameLimit{ 60 }, quantity_of_blocksX{ 12 }, quantity_of_blocksY{ 7 };
enum TYPE
{
	ORDINARY,
	INDESTRUCTIBLE,
	BONUS_INSIDE,
	SPEED_INCREASING,
	WITH_HEALTH
};


class Block : public Rectange_shaped_objects
{
public:
	int type = ORDINARY;
	bool destructible = true;
	bool destroyed = false;
	
	Block(int x, int y) : Rectange_shaped_objects(x, y, block_height, block_width, sf::Color::Yellow) {};
	Block(int x, int y, int height, int width, sf::Color color) : Rectange_shaped_objects(x, y, height, width, color) {};
	void set_type(int _type)
	{
		type = _type;
		switch (_type)
		{
		case INDESTRUCTIBLE:
			destructible = false;
			break;
		case WITH_HEALTH:
			destructible = true;
		default:
			break;
		}
	}
};

class Moving_block : public Block
{
	sf::Vector2f velocity{ moving_block_velocity, 0 };
public:
	Moving_block(int x, int y) : Block(x, y) { set_type(WITH_HEALTH); };
	void reflect_velocity() { velocity.x *= -1; }
	void update_and_move()
	{
		rect.move(velocity);
		if (get_left() <= 0 || get_right() >= windowWidth)
			reflect_velocity();
	}
};

class Border : public Block
{
public:
	Border() : Block(512, 760, 6, 1024, sf::Color::Cyan) {};
};

