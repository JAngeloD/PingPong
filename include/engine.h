#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include "state.h"
#include "startstate.h"
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


        static constexpr int GAMESTATEID = 0;
        static constexpr int PAUSESTATEID = 1;
        static constexpr int STARTSTATEID = 2;
        static constexpr int RESTARTID = 3;
        static const int xRes = 800;
        static const int yRes = 600;
    private:
        state* currentState; //Stores pointer to the current state

        //States of the game
        startstate start;
        gamestate game;
        pausestate pause;

        sf::Vector2f res;
};

#endif // ENGINE_H
