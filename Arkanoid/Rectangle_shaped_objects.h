#pragma once
#include <SFML/Graphics.hpp>

class Rectange_shaped_objects : public sf::Drawable
{
protected:
	sf::RectangleShape rect;
	float height;
	float width;
	void draw(sf::RenderTarget& game, sf::RenderStates states) { game.draw(rect, states); }
public:
	Rectange_shaped_objects(int x, int y, float height_of_block, float width_of_block, sf::Color color): height(height_of_block), width(width_of_block)
	{
		rect.setPosition(x, y);
		rect.setSize(sf::Vector2f{ width_of_block, height_of_block });
		rect.setFillColor(color);
		rect.setOrigin(width_of_block / 2.f, height_of_block / 2.f);
	};
	sf::Vector2f get_position() { return rect.getPosition(); }
	float get_left() { rect.getPosition().x - rect.getSize().x / 2.f; };
	float get_right() { rect.getPosition().x + rect.getSize().x / 2.f; };
	float get_top() { rect.getPosition().y - rect.getSize().y / 2.f; };
	float get_bottom() { rect.getPosition().y + rect.getSize().y / 2.f; };
};