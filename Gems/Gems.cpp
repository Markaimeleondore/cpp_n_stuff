#include <SFML/Graphics.hpp>
#include "Gem.h"
#include "Frame.h"


using namespace sf;

int main()
{
    

    RenderWindow game(VideoMode(800, 600), "Gems");
    game.setFramerateLimit(60);
    Frame g;
    g.fulfill();
    while (game.isOpen())
    {
        game.clear(Color::White);
        Event event;
        while (game.pollEvent(event))
        {
            if (event.type == Event::Closed)
                game.close();
        }

        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                game.draw(*g.grid[i][j]);
            }
        }



        game.display();
    }
    return 0;
}