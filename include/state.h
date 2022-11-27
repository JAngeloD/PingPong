#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class state
{
    public:
        virtual ~state();

        virtual void render(sf::RenderWindow* window);
        virtual int handleEvents(sf::Event event);
        virtual void update();
};

#endif // STATE_H
