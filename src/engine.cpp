#include "engine.h"

engine::engine() {
    res = sf::Vector2f(800, 600);
    window = new sf::RenderWindow(sf::VideoMode(res.x, res.y), "SFML works!");
    window->setVerticalSyncEnabled(true);

    currentState = &game;
}

engine::~engine() {
    window->close();
}

void engine::render() {

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {window->close();}

            int stateChange = currentState->handleEvents(event);
            switch (stateChange) {
                case 1:
                    currentState = &pause;
                    break;
                case 0:
                    currentState = &game;
                    break;
            }
        }

        window->clear();
        currentState->render(window);
        window->display();
    }
}

