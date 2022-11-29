#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "paddle.h"
#include "ball.h"

#include <math.h>
#include <string>
#include <chrono>
#include <thread>

class gamestate : public state
{
    public:
        gamestate();
        virtual ~gamestate();

        void render(sf::RenderWindow* window) override;
        int handleEvents(sf::Event event) override;
        void initStart();

    private:
        void update() override;

        //Game Arena
        sf::RectangleShape midLine;
        sf::Font font;
        sf::Text cpuScore;
        sf::Text playerScore;

        //Game objects
        paddle cpuPlayer;
        paddle player;
        ball pongBall;

        //Boundaries
        std::pair<sf::Vector2f, sf::Vector2f> topBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> bottomBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> rightBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> leftBoundary;

        std::pair<sf::Vector2f, sf::Vector2f> playerPaddleBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> cpuPlayerPaddleBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> pongBallBoundary;

        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> playerBoundaries;
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> cpuBoundaries;
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> ballBoundaries;

};

#endif // GAMESTATE_H
