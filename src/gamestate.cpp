#include "gamestate.h"
#include "paddle.h"
#include "engine.h"

gamestate::gamestate() {
    //Initializes object textures
    if(!player.getTexture()->loadFromFile("res\\Paddle.png")) {
        std::cout << "Player padde texture was could not load!" << std::endl;
    }
    if(!cpuPlayer.getTexture()->loadFromFile("res\\Paddle.png")) {
        std::cout << "CPU paddle texture was not loaded" << std::endl;
    }
    if(!pongBall.getTexture()->loadFromFile("res\\ball.png")) {
        std::cout << "Pong ball texture was not loaded" << std::endl;
    }
    player.getSprite()->setTexture(*player.getTexture());
    cpuPlayer.getSprite()->setTexture(*cpuPlayer.getTexture());
    pongBall.getSprite()->setTexture(*pongBall.getTexture());

    //Initializes the mid line in the arena
    midLine.setSize(sf::Vector2f(2, engine::yRes));
    midLine.setPosition(engine::xRes / 2, 0);

    //Initializes the score for each player
    if(!font.loadFromFile("res\\Play-Bold.ttf")) {
        std::cout << "Game state font was not loaded" << std::endl;
    }
    cpuScore.setFont(font);
    cpuScore.setString("0");
    cpuScore.setCharacterSize(32);
    cpuScore.setPosition(engine::xRes * 0.9, 0);

    playerScore.setFont(font);
    playerScore.setString("0");
    playerScore.setCharacterSize(32);
    playerScore.setPosition(engine::xRes * 0.1, 0);

    //Initializes object starting position
    //TODO:  (refactor to be dynamic)
    player.setPosition(0.0f, 300.0f - 42.0f);
    cpuPlayer.setPosition(engine::xRes- 15.0f, 300.0f - 42.0f);
    pongBall.setPosition(400.0f - 7.0f, 300.0f - 7.0f);

    //Initializes object boundaries
    topBoundary = std::make_pair(sf::Vector2f(-1,-100), sf::Vector2f(engine::xRes, 100));
    bottomBoundary = std::make_pair(sf::Vector2f(-1,600), sf::Vector2f(engine::xRes,200));
    rightBoundary = std::make_pair(sf::Vector2f(engine::xRes, -1), sf::Vector2f(400, 600));
    leftBoundary = std::make_pair(sf::Vector2f(engine::xRes, -100), sf::Vector2f(10, 100));

    playerPaddleBoundary = player.getBoundary();
    cpuPlayerPaddleBoundary = cpuPlayer.getBoundary();
    pongBallBoundary = pongBall.getBoundary();

    //Packages and assigns Boundaries to the objects
    playerBoundaries = {topBoundary, bottomBoundary};
    cpuBoundaries = {topBoundary, bottomBoundary};
    ballBoundaries = {topBoundary, bottomBoundary, playerPaddleBoundary, cpuPlayerPaddleBoundary};
    player.setBoundary(&playerBoundaries);
    cpuPlayer.setBoundary(&cpuBoundaries);
    pongBall.setBoundary(&ballBoundaries);

    //Initializes starting velocity of the pong ball
    pongBall.startVelocity();
}

gamestate::~gamestate() {}


void gamestate::render(sf::RenderWindow* window) {
    update();

    window->draw(*player.getSprite());
    window->draw(*cpuPlayer.getSprite());
    window->draw(*pongBall.getSprite());
    window->draw(midLine);
    window->draw(cpuScore);
    window->draw(playerScore);
}


int gamestate::handleEvents(sf::Event event) {
    //Handles events when a key is pressed
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {player.up = true;}
        else if (event.key.code == sf::Keyboard::Down) {player.down = true;}

        //Changes the current state of the game to the pause state
        if (event.key.code == sf::Keyboard::Escape) {
            return engine::PAUSESTATEID;
        }
    }
    //Handles events when a key is released
    else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {player.up = false;}
        else if (event.key.code == sf::Keyboard::Down) {player.down = false;}
    }

    return engine::GAMESTATEID;
}

void gamestate::update() {
    //player paddle movement updates
    //TODO:  (refactor to be dynamic)
    player.setVelocity(0.0f, 0.0f);
    if (player.up) {
        player.setVelocity(0.0f, -2.0f);
        playerPaddleBoundary = player.getBoundary();
    }
    if (player.down) {
        player.setVelocity(0.0f, 2.0f);
        playerPaddleBoundary = player.getBoundary();
    }

    //cpu paddle movement updates (impossible to beat, need to refactor)
    float finalCpuVelocity = pongBall.getYVelocity();
    if(pongBall.getYVelocity() < 0 && cpuPlayer.getYPosition() < pongBall.getYPosition()) {
        finalCpuVelocity = 0;
    }
    else if (pongBall.getYVelocity() > 0 && cpuPlayer.getYPosition() > pongBall.getYPosition()) {
        finalCpuVelocity = 0;
    }
    if(pongBall.getXVelocity() >= 0) {cpuPlayer.setVelocity(0.0f, finalCpuVelocity);}
    cpuPlayerPaddleBoundary = cpuPlayer.getBoundary();

    //Updates boundaries
    playerBoundaries = {topBoundary, bottomBoundary};
    cpuBoundaries = {topBoundary, bottomBoundary};
    ballBoundaries = {topBoundary, bottomBoundary, playerPaddleBoundary, cpuPlayerPaddleBoundary};
    player.setBoundary(&playerBoundaries);
    cpuPlayer.setBoundary(&cpuBoundaries);
    pongBall.setBoundary(&ballBoundaries);

    //Moves every object based on current velocity set
    pongBall.move();
    player.move();
    cpuPlayer.move();

    //Checks for any goals
    int nextScore = 0;
    if (pongBall.getXPosition() + pongBall.getWidth() < 0) {
        nextScore = std::stoi(cpuScore.getString().toAnsiString()) + 1;
        cpuScore.setString(std::to_string(nextScore));
        std::this_thread::sleep_for(std::chrono::seconds(0.5));
        pongBall.setPosition(400.0f - 7.0f, 300.0f - 7.0f);
    }
    if (pongBall.getXPosition() + pongBall.getWidth() > engine::xRes) {
        nextScore = std::stoi(playerScore.getString().toAnsiString()) + 1;
        playerScore.setString(std::to_string(nextScore));
        std::this_thread::sleep_for(std::chrono::seconds(0.5));
        pongBall.setPosition(400.0f - 7.0f, 300.0f - 7.0f);
    }
}



