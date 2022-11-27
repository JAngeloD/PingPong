#include "startstate.h"
#include "engine.h"

startstate::startstate() {
    if(!font.loadFromFile("res\\Play-Bold.ttf")) {
        std::cout << "initializing pause state caused an error" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(42);
    text.setFillColor(sf::Color::White);

    text.setString("Press Any Button To Start");

    int xOffset = (text.getCharacterSize() * text.getString().getSize()) / 4;
    int yOffset = (text.getCharacterSize());
    text.move((engine::xRes / 2) - xOffset, (engine::yRes / 2) - yOffset);

    std:: cout << text.getPosition().y << std::endl;
}

startstate::~startstate() {}

void startstate::render(sf::RenderWindow* window) {
    window->draw(text);
}

int startstate::handleEvents(sf::Event event) {
    //Handles events when a key is pressed
    if (event.type == sf::Event::KeyPressed) {
        return engine::GAMESTATEID;
    }
    //Handles events when a key is released
    else if (event.type == sf::Event::KeyReleased) {
    }

    return engine::STARTSTATEID;
}
