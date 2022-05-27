#include "Field.h"
#include <time.h>

int main()
{
    srand(time(0));
    
    Field instance;
    instance.fulfill();
    int click_counter = 0, x_pressed, y_pressed;
    while (instance.game.isOpen())
    {
        instance.actions(click_counter, x_pressed, y_pressed);
        instance.update();
        instance.drawAll();
    }

    return 0;
}
