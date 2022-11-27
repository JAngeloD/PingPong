#include "engine.h"

//Initializes the game window and current state
engine::engine() {
    res = sf::Vector2f(xRes, yRes);
    window = new sf::RenderWindow(sf::VideoMode(res.x, res.y), "SFML works!");
    window->setVerticalSyncEnabled(true);

    currentState = &start;
}

engine::~engine() {window->close();}

//Render
void engine::render() {
    while (window->isOpen())
    {
        //Section where events are being handled from the current state of the game
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {window->close();} //Handles closing the window

            // Gets the ID returned from handle events to listen to any requests for changing states
            int stateChange = currentState->handleEvents(event);
            switch (stateChange) {
                case engine::STARTSTATEID:
                    currentState = &start;
                    break;
                case engine::PAUSESTATEID:
                    currentState = &pause;
                    break;
                case engine::GAMESTATEID:
                    currentState = &game;
                    break;
                case engine::RESTARTID:
                    game = gamestate();
                    currentState = &game;
                    break;
            }
        }

        // Everything finalized from updates and draws on screen
        window->clear();
        currentState->render(window);
        window->display();
    }
}

