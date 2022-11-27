#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "state.h"

class engine;
class startstate : public state
{
    public:
        startstate();
        virtual ~startstate();

        void render(sf::RenderWindow* window) override;
        int handleEvents(sf::Event event) override;

    private:
        sf::Font font;
        sf::Text text;
};

#endif // STARTSTATE_H
