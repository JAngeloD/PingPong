#include "gamestate.h"
#include "paddle.h"

gamestate::gamestate() {
    //Initializes object textures
    if(!player.getTexture()->loadFromFile("bin\\Debug\\Paddle.png")) {
        std::cout << "Player padde texture was could not load!" << std::endl;
    }
    if(!cpuPlayer.getTexture()->loadFromFile("bin\\Debug\\Paddle.png")) {
        std::cout << "CPU paddle texture was not loaded" << std::endl;
    }
    player.getSprite()->setTexture(*player.getTexture());
    cpuPlayer.getSprite()->setTexture(*cpuPlayer.getTexture());

    //Initializes object starting positions (refactor to be dynamic)
    player.setPosition(0.0f, 300.0f - 42.0f);
    cpuPlayer.setPosition(800.0f - 15.0f, 300.0f - 42.0f);

    //Initializes object boundaries
    topBoundary = std::make_pair(sf::Vector2f(0,0), sf::Vector2f(800, 0));
    bottomBoundary = std::make_pair(sf::Vector2f(0,600), sf::Vector2f(800,0));
    playerPaddleBoundary = player.getBoundary();
    cpuPlayerPaddleBoundary = cpuPlayer.getBoundary();

    //Packages and assigns Boundaries to the objects
    playerBoundaries = {topBoundary, bottomBoundary};
    cpuBoundaries = {topBoundary, bottomBoundary};
    player.setBoundary(&playerBoundaries);
    cpuPlayer.setBoundary(&cpuBoundaries);

}

gamestate::~gamestate() {}

void gamestate::render(sf::RenderWindow* window) {
    update();

    window->draw(*player.getSprite());
    window->draw(*cpuPlayer.getSprite());
}

void gamestate::handleEvents(sf::Event event) {
    //Handles events when a key is pressed
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {player.up = true;}
        else if (event.key.code == sf::Keyboard::Down) {player.down = true;}
    }
    //Handles events when a key is released
    else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {player.up = false;}
        else if (event.key.code == sf::Keyboard::Down) {player.down = false;}
    }
    //Handles events when the mouse left click is pressed
    else if (event.type == sf::Event::MouseButtonPressed) {

    }


}

void gamestate::update() {
    //player paddle movement updates
    if (player.up) {
        player.move(0.0f, -2.0f);
        playerPaddleBoundary = player.getBoundary();
    }
    if (player.down) {
        player.move(0.0f, 2.0f);
        playerPaddleBoundary = player.getBoundary();
    }
}



