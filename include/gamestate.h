#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "paddle.h"

class gamestate : public state
{
    public:
        gamestate();
        virtual ~gamestate();

        void render(sf::RenderWindow* window) override;
        void handleEvents(sf::Event event) override;
        void update() override;

    private:
        paddle cpuPlayer;
        paddle player;

        std::pair<sf::Vector2f, sf::Vector2f> topBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> bottomBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> playerPaddleBoundary;
        std::pair<sf::Vector2f, sf::Vector2f> cpuPlayerPaddleBoundary;

        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> playerBoundaries;
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> cpuBoundaries;
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> ballBoundaries;

};

#endif // GAMESTATE_H
