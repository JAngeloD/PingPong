#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class state
{
    public:
        state::state() {}
        virtual ~state();

        virtual void render(sf::RenderWindow* window);
        virtual void handleEvents(sf::Event* event);
};

#endif // STATE_H
