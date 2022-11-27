#include "pausestate.h"
#include "engine.h"

pausestate::pausestate() {
    //Initializes the font to be used
    if(!font.loadFromFile("res\\Play-Bold.ttf")) {
        std::cout << "initializing pause state caused an error" << std::endl;
    }

    //Creates the continue text
    continueText.setFont(font);
    continueText.setCharacterSize(42);
    continueText.setFillColor(sf::Color::White);

    continueText.setString("Press 'SPACE' to continue");

    int xOffset = (continueText.getCharacterSize() * continueText.getString().getSize()) / 4;
    int yOffset = (continueText.getCharacterSize() * 2);
    continueText.move((engine::xRes / 2) - xOffset, (engine::yRes / 2) - yOffset);

    //Creates the restart continueText
    restartText.setFont(font);
    restartText.setCharacterSize(42);
    restartText.setFillColor(sf::Color::White);

    restartText.setString("Press 'R' to restart game");

    xOffset = (restartText.getCharacterSize() * restartText.getString().getSize()) / 4;
    restartText.move((engine::xRes / 2) - xOffset, engine::yRes / 2);

}

pausestate::~pausestate() {}

void pausestate::render(sf::RenderWindow* window) {
    window->draw(restartText);
    window->draw(continueText);
}

int pausestate::handleEvents(sf::Event event) {
    //Handles events when a key is pressed
    if (event.type == sf::Event::KeyPressed) {
        // "Unpauses" the game by switching to the gamestate
        if (event.key.code == sf::Keyboard::Space) {
            return engine::GAMESTATEID;
        }
        if (event.key.code == sf::Keyboard::R) {
            return engine::RESTARTID;
        }
    }
    //Handles events when a key is released
    else if (event.type == sf::Event::KeyReleased) {
    }

    return engine::PAUSESTATEID;
}
