#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class object
{
    public:
        virtual ~object();

        sf::Texture getTexture() {return texture;}
        sf::Sprite getSprite() {return sprite;}

        float getXPosition() {return x;}
        float getYPosition() {return y;}

        void move(float x, float y);

    protected:
        sf::Texture texture;
        sf::Sprite sprite;

        float x;
        float y;
};

#endif // OBJECT_H
