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
};

#endif // GAMESTATE_H
