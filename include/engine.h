#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <stdlib.h>

#include "string.h"
#include "state.h"
#include "gamestate.h"
#include "menustate.h"
#include "pausestate.h"

class engine
{
    public:
        engine(); //Initialzes the window and every state.
        virtual ~engine();

        void render(); //Starts the game play loop
        sf::RenderWindow* window;

    private:
        state* currentState; //Stores pointer to the current state

        //States of the game
        menustate menu;
        pausestate pause;
        gamestate game;
};

#endif // ENGINE_H
