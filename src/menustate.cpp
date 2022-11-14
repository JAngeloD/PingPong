#include "menustate.h"

menustate::menustate() {

    try {
        initializeExitButton();
        initializePlayButton();
    }
    catch(const std::exception& e) {
        std::cout << "Menu State encounted an error" << std::endl;
    }
}

menustate::~menustate() {}

void menustate::render(sf::RenderWindow* window) {

}

void menustate::handleEvents(sf::Event) {

}

/***********************************************
 * Functions to objects/UI elements in the state
 ***********************************************
 */
void menustate::initializePlayButton() {

    //Error occured
    throw exception;
}
void menustate::initializeExitButton() {

    //Error occured
    throw exception;
}
