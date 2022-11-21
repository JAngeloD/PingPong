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
            currentState->handleEvents(event);
        }
        window->clear();
        currentState->render(window);
        window->display();
    }
}

