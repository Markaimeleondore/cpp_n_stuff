#include "Frame.h"

void Frame::fulfill()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			grid[i][j] = new Gem(i * 54, j * 54);
			switch (rand() % 5)
			{
			case 0:
				grid[i][j]->setFillColor(sf::Color::Blue);
				break;
			case 1:
				grid[i][j]->setFillColor(sf::Color::Red);
				break;
			case 2:
				grid[i][j]->setFillColor(sf::Color::Green);
				break;
			case 3:
				grid[i][j]->setFillColor(sf::Color::Cyan);
				break;
			case 4:
				grid[i][j]->setFillColor(sf::Color::Yellow);
				break;
			}
		}
	}
	swap_flag = false;
	click_counter = 0;
}

void Frame::check_matches()
{

}

