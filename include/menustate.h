#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
class menustate : public state
{
    public:
        virtual ~menustate();

        void render(sf::RenderWindow* window) override;
        void handleEvents(sf::RenderWindow* window) override;

    private:
        void initializePlayButton();
        void initializeExitButton();

};

#endif // MENUSTATE_H
