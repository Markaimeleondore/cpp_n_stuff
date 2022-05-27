#include "Bonus.h"
#include "Field.h"
#include <set>
void Color_changer::action(sf::RenderWindow& game, Gem grid[10][10])
{
	choose_others(grid);
	this_color = grid[x][y].rect->getFillColor();
	grid[others[0].first][others[0].second].rect->setFillColor(sf::Color::Black);
	grid[others[1].first][others[1].second].rect->setFillColor(sf::Color::Black);
	grid[x][y].rect->setFillColor(sf::Color::Black);
	game.draw(*grid[others[0].first][others[0].second].rect);
	game.draw(*grid[others[1].first][others[1].second].rect);
	game.draw(*grid[x][y].rect);
	game.display();
	sf::sleep(sf::seconds(0.5f));
	grid[others[0].first][others[0].second].rect->setFillColor(this_color);
	grid[others[1].first][others[1].second].rect->setFillColor(this_color);
	grid[x][y].rect->setFillColor(this_color);
	game.draw(*grid[others[0].first][others[0].second].rect);
	game.draw(*grid[others[1].first][others[1].second].rect);
	game.draw(*grid[x][y].rect);
	sf::sleep(sf::seconds(0.3f));
}
void Bomb::action(sf::RenderWindow& game, Gem grid[10][10])
{
	choose_others(grid);
	for (auto& gem : others)
	{
		grid[gem.first][gem.second].rect->setFillColor(sf::Color::White);
		game.draw(*grid[gem.first][gem.second].rect);
	}
	grid[x][y].rect->setFillColor(sf::Color::White);
	game.draw(*grid[x][y].rect);
	game.display();
	sf::sleep(sf::seconds(0.7f));
}

void Color_changer::choose_others(Gem grid[10][10])
{
	int x1_pos = rand() % field_size + 1, y1_pos = rand() % field_size + 1, x2_pos = rand() % field_size + 1, y2_pos = rand() % field_size + 1;
	if (abs(x2_pos - x1_pos) + abs(y2_pos - y1_pos) == 1)
	{
		if (x1_pos >= field_size / 2)
		{
			x1_pos--;
			if (y1_pos >= field_size / 2)
				y1_pos--;
			else
				y1_pos++;
		}
		else
		{
			x1_pos++;
			if (y1_pos >= field_size / 2)
				y1_pos--;
			else
				y1_pos++;
		}
	}
	others.push_back(std::make_pair(x1_pos, y1_pos));
	others.push_back(std::make_pair(x2_pos, y2_pos));
}

void Bomb::choose_others(Gem grid[10][10])
{
	std::set<std::pair<int, int>> positions;
	while (positions.size() != 4)
	{
		positions.emplace(std::make_pair(rand() % field_size + 1, rand() % field_size + 1));
	}
	for (auto& pos : positions)
		others.push_back(pos);
}
