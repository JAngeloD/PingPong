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

int pausestate::handleEvents(sf::Event event) {

}


/***********************************************
 * Functions to objects/UI elements in the state
 ***********************************************
 */
void pausestate::initializeResumeButton() {

}
void pausestate::initializeQuitButton() {

}
