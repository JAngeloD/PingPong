#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
class gamestate : public state
{
    public:
        gamestate();
        virtual ~gamestate();

        void render(sf::RenderWindow* window) override;
        void handleEvents(sf::Event) override;

    private:
        void initializeUI();
        void initializePlayerPaddle();
        void initializeAIPaddle();
        void initializeBall();
};

#endif // GAMESTATE_H
