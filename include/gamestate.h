#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <math.h>
#include "state.h"
#include "paddle.h"
#include "ball.h"

class gamestate : public state
{
    public:
        gamestate();
        virtual ~gamestate();

        void render(sf::RenderWindow* window) override;
        void handleEvents(sf::Event event) override;

    private:
        void update() override;

        paddle cpuPlayer;
        paddle player;
        ball pongBall;

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
