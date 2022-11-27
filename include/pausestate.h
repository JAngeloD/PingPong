#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"

class engine;
class pausestate : public state
{
    public:
        pausestate();
        virtual ~pausestate();

        void render(sf::RenderWindow* window) override;
        int handleEvents(sf::Event event) override;

    private:
        sf::Font font;
        sf::Text text;
};

#endif // PAUSESTATE_H
