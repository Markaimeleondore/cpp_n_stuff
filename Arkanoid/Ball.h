#pragma once
#include <SFML/Graphics.hpp>
constexpr float default_speed{ 5.0f };

class Ball : public sf::Drawable
{
protected:
	sf::CircleShape ball;
	float radius = 8.f;
public:
	void draw(sf::RenderTarget& game, sf::RenderStates states) { game.draw(ball, states); }
	float speed = 5.0f;
	sf::Vector2f xy_velocity = { speed, speed };
	Ball(int x, int y)
	{
		ball.setPosition(x, y);
		ball.setRadius(radius);
		ball.setFillColor(sf::Color::Black);
		ball.setOrigin(radius, radius);
	}

	void hold_inside_the_window_while_moving(unsigned int height, unsigned int width);

	float get_left() { return ball.getPosition().x - radius; };
	float get_right() { return ball.getPosition().x + radius; };
	float get_top() { return ball.getPosition().y - radius; };
	float get_bottom() { return ball.getPosition().y + radius; };
	void set_position(int x, int y) { ball.setPosition(x, y); };
	void set_position(sf::Vector2f position) { ball.setPosition({ position.x, position.y - radius + speed }); }
	sf::Vector2f get_position() { return ball.getPosition(); };

	void move_left() { xy_velocity.x = -speed; };
	void move_right() { xy_velocity.x = speed; };
	void move_up() { xy_velocity.y = -speed; };
	void move_down() { xy_velocity.y = speed; };

	void increase_speed() { speed++; };
	void decrease_speed() { speed--; };
	void reset_speed() { speed = default_speed; };
	void bounce_x() { xy_velocity.x = -xy_velocity.x; };

};