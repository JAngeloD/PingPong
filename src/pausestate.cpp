#include "pausestate.h"

pausestate::pausestate() {

    try {
        initializeResumeButton();
        initializeQuitButton();
    }
    catch(const std::exception& e) {
        std::cout << "Penu State encounted an error" << std::endl;
    }
}

pausestate::~pausestate() {}

void pausestate::render(sf::RenderWindow* window) {

}

void pausestate::handleEvents(sf::Event) {

}


/***********************************************
 * Functions to objects/UI elements in the state
 ***********************************************
 */
void menustate::initializeResumeButton() {

    //Error occured
    throw exception;
}
void menustate::initializeQuitButton() {

    //Error occured
    throw exception;
}
