#include "engine.h"

engine::engine() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
    window->setVerticalSyncEnabled(true);

    currentState = &state1;
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
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else if(event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    if(currentState == &state1) {

                        currentState = &state2;
                    }
                    else {
                        currentState = &state1;
                    }
                }
                currentState->handleEvents(window);
            }

        }
        window->clear();
        currentState->render(window);
        window->display();
    }
}

