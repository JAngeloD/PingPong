#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <stdlib.h>

#include "string.h"
#include "state.h"

class engine
{
    public:
        engine();
        virtual ~engine();

        void render();

        sf::RenderWindow* window;
        state* currentState;
};

#endif // ENGINE_H
