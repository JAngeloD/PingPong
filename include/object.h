#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class object
{
    public:
        virtual ~object();

        sf::Texture* getTexture() {return& texture;}
        sf::Sprite* getSprite() {return& sprite;}

        float getXPosition() {return x;}
        float getYPosition() {return y;}


        void move(float x, float y) {
            sf::Vector2f pos(x, y);

            sprite.move(pos);
        }

        void setPosition(float x, float y) {
            sf::Vector2f pos(x, y);
            sprite.setPosition(pos);
        }

        //X and Y pos
        float x;
        float y;

        //Current bool movement of the object
        bool up = false;
        bool down = false;

        //

    protected:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // OBJECT_H
