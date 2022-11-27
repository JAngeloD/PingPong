#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "gamestate.h"
#include "pausestate.h"

class engine
{
    public:
        engine(); //Initialzes the window and every state.
        virtual ~engine();

        sf::Vector2f getResolution() {return res;}

        void render(); //Starts the game play loop
        sf::RenderWindow* window;

    private:
        state* currentState; //Stores pointer to the current state

        //States of the game
        gamestate game;
        pausestate pause;

        sf::Vector2f res;
};

#endif // ENGINE_H
