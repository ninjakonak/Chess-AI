#include <iostream>
#include"include/GameConsole.h"

int main()
{
    GameConsole console;

    while (console.Running()) {
        console.Update();
        console.Render();
    }
}
