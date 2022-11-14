#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"
class pausestate : public state
{
    public:
        pausestate();
        virtual ~pausestate();

        void render(sf::RenderWindow* window) override;
        void handleEvents(sf::Event) override;

    private:
        void initializeResumeButton();
        void initializeQuitButton();
};

#endif // PAUSESTATE_H
