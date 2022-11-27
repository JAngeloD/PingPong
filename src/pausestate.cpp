#include "pausestate.h"
#include "engine.h"

pausestate::pausestate() {
    if(!font.loadFromFile("res\\Play-Bold.ttf")) {
        std::cout << "initializing pause state caused an error" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(42);
    text.setFillColor(sf::Color::White);

    text.setString("Press space to continue");

    int xOffset = (text.getCharacterSize() * text.getString().getSize()) / 4;
    int yOffset = (text.getCharacterSize());
    text.move((engine::xRes / 2) - xOffset, (engine::yRes / 2) - yOffset);

    std:: cout << text.getPosition().y << std::endl;
}

pausestate::~pausestate() {}

void pausestate::render(sf::RenderWindow* window) {
    window->draw(text);
}

int pausestate::handleEvents(sf::Event event) {
    //Handles events when a key is pressed
    if (event.type == sf::Event::KeyPressed) {
        // "Unpauses" the game by switching to the gamestate
        if (event.key.code == sf::Keyboard::Space) {
            return engine::GAMESTATEID;
        }
    }
    //Handles events when a key is released
    else if (event.type == sf::Event::KeyReleased) {
    }

    return engine::PAUSESTATEID;
}
