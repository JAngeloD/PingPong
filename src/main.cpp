#include "main.h"
#include <SFML/Graphics.hpp>

#include "engine.h"

engine *Engine = nullptr;

int main()
{
    Engine = new engine();
    Engine->render();

    return 0;
}
