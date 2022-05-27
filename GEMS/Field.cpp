#include "Field.h"
#include "Queue"
#include "Set"
using namespace std;

void Field::fulfill()
{
	for (int i = 1; i <= field_size; i++)
	{
		for (int j = 1; j <= field_size; j++)
		{
			grid[i][j].rect = new sf::RectangleShape(sf::Vector2f(54.f, 54.f));
			switch (rand() % 6)
			{
			case 0: 
				grid[i][j].rect->setFillColor(sf::Color::Blue);
				break;
			case 1:
				grid[i][j].rect->setFillColor(sf::Color::Green);
				break;
			case 2:
				grid[i][j].rect->setFillColor(sf::Color::Red);
				break;
			case 3:
				grid[i][j].rect->setFillColor(sf::Color::Cyan);
				break;
			case 4:
				grid[i][j].rect->setFillColor(sf::Color::Black);
				break;
			case 5:
				grid[i][j].rect->setFillColor(sf::Color::Yellow);
				break;
			}
			grid[i][j].rect->setPosition(sf::Vector2f(i * 54.f, j * 54.f));
		}
	}
}

void Field::check_matches()
{
	for (int i = 1; i <= field_size; i++)
	{
		for (int j = 1; j <= field_size; j++)
		{
			
			vector<pair<int, int>> suspects;
			set < pair<int, int>> on_delete;
			suspects.push_back(make_pair(i, j));
			on_delete.emplace(make_pair(i, j));
			for (int i = 0; i < suspects.size(); i++)
			{
				pair<int, int> id = suspects[i];
				if (id.second != field_size && grid[id.first][id.second + 1].match_counter == 0 && compare(grid[id.first][id.second].rect, grid[id.first][id.second + 1].rect))
				{
					suspects.push_back(make_pair(id.first, id.second + 1));
					on_delete.emplace(make_pair(id.first, id.second + 1));
					grid[id.first][id.second + 1].match_counter++;
				}
				if (id.second != 1 && grid[id.first][id.second - 1].match_counter == 0 && compare(grid[id.first][id.second].rect, grid[id.first][id.second - 1].rect))
				{
					suspects.push_back(make_pair(id.first, id.second - 1));
					on_delete.emplace(make_pair(id.first, id.second - 1));
					grid[id.first][id.second - 1].match_counter++;
				}
				if (id.first != field_size && grid[id.first + 1][id.second].match_counter == 0 && compare(grid[id.first][id.second].rect, grid[id.first + 1][id.second].rect))
				{
					suspects.push_back(make_pair(id.first + 1, id.second));
					on_delete.emplace(make_pair(id.first + 1, id.second));
					grid[id.first + 1][id.second].match_counter++;
				}
				if (id.first != 1 && grid[id.first - 1][id.second].match_counter == 0 && compare(grid[id.first][id.second].rect, grid[id.first - 1][id.second].rect))
				{
					suspects.push_back(make_pair(id.first - 1, id.second));
					on_delete.emplace(make_pair(id.first - 1, id.second));
					grid[id.first - 1][id.second].match_counter++;
				}

			}
				for (auto& ids : on_delete)
				{
					if (on_delete.size() >= 3)
					{
					grid[ids.first][ids.second].rect->setFillColor(sf::Color::White);
					}
					grid[ids.first][ids.second].match_counter = 0;
				}
			
	
		}
	}
}

void Field::draw()
{
	for (int i = 1; i <= field_size; i++)
	{
		for (int j = 1; j <= field_size; j++)
		{
			game.draw(*grid[i][j].rect);
		}
		sf::sleep(sf::seconds(0.005f));
	}
}

void Field::rebuild()
{
	for (int i = 1; i <= field_size; i++)
	{
		for (int j = field_size; j >= 1; j--)
		{
			sf::Color tmp;
			if (grid[i][j].rect->getFillColor() == sf::Color::White) 
			{
				for(int k = j - 1; k >= 1; k--)
				{
					if (grid[i][k].rect->getFillColor() != sf::Color::White) 
					{
						grid[i][j].rect->setFillColor(grid[i][k].rect->getFillColor());
						grid[i][k].rect->setFillColor(sf::Color::White);
						game.clear(sf::Color::White);
						draw();
						game.display();
						break;
					}
				}
			}
		}
	}
}

void Field::change_positions(int x_fs, int y_fs, int x_sc, int y_sc)
{
	sf::Color tmp;
	if (abs(x_sc - x_fs) + abs(y_sc - y_fs) == 1)
	{
		tmp = grid[x_fs][y_fs].rect->getFillColor();
		grid[x_fs][y_fs].rect->setFillColor(grid[x_sc][y_sc].rect->getFillColor());
		grid[x_sc][y_sc].rect->setFillColor(tmp);
		game.draw(*grid[x_fs][y_fs].rect);
		game.draw(*grid[x_sc][y_sc].rect);
		game.display();
		sf::sleep(sf::seconds(0.2f));
	}
}

void Field::update()
{
	check_matches();
	rebuild();
	repair_gems();
}

void Field::actions(int& click_counter, int& x_pressed, int& y_pressed)
{
	std::pair<int, int> cur_click;
	sf::Event event;
	game.setFramerateLimit(60);
	while (game.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			game.close();

		if (event.type == sf::Event::MouseButtonPressed) 
		{
			if (event.key.code == sf::Mouse::Left) 
			{
				sf::Vector2i position = sf::Mouse::getPosition(game);
				cur_click = { position.x / gem_size , position.y / gem_size };

				click_counter++;
				if (click_counter == 2) 
				{
					change_positions(cur_click.first, cur_click.second, x_pressed, y_pressed);

					click_counter = 0;
				}
				x_pressed = cur_click.first;
				y_pressed = cur_click.second;
			}
		}
	}
}

void Field::drawAll()
{
	game.clear(sf::Color::White);
	draw();
	game.display();
}

void Field::repair_gems()
{
	for (int i = 1; i <= field_size; i++)
	{
		int k = 1;

		while (grid[i][k].rect->getFillColor() == sf::Color::White && k <= field_size) 
		{
			sf::Color tmp;
			switch (rand() % 6)
			{
			case 0:
				tmp = sf::Color::Blue;
				break;
			case 1:
				tmp = sf::Color::Green;
				break;
			case 2:
				tmp =  sf::Color::Red;
				break;
			case 3:
				tmp = sf::Color::Cyan;
				break;
			case 4:
				tmp = sf::Color::Black;
				break;
			case 5:
				tmp = sf::Color::Yellow;
				break;
			}
			if (k == 1) 
			{
				grid[i][k].rect->setFillColor(tmp);
			}
			else 
			{
				for(int j = k; j >= 2; j--)
				{
					sf::Color cur = grid[i][j - 1].rect->getFillColor();
					grid[i][j].rect->setFillColor(cur);
					grid[i][j - 1].rect->setFillColor(tmp);

					game.clear(sf::Color::White);
					draw();
					game.display();
				}
			}
			sf::sleep(sf::seconds(0.001f));
			k++;
		}
	}
}
