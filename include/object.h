#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class object
{
    public:
        virtual ~object();

        sf::Texture* getTexture() {return& texture;}
        sf::Sprite* getSprite() {return& sprite;}
        float getXPosition() {return sprite.getPosition().x;}
        float getYPosition() {return sprite.getPosition().y;}
        float getWidth() {return texture.getSize().x;}
        float getHeight() {return texture.getSize().y;}

        std::pair<sf::Vector2f, sf::Vector2f> getBoundary() {
            sf::Vector2f vertex1(sprite.getPosition().x, sprite.getPosition().y);
            sf::Vector2f vertex2(texture.getSize().x, texture.getSize().y);
            return std::make_pair(vertex1, vertex2);
        }

        virtual void move(float x, float y) {
            //Checks if object is outside of boundary before moving
            for(std::pair<sf::Vector2f, sf::Vector2f> vertex : *boundaries) {
                if ((x + getXPosition() >= vertex.first.x && x + getXPosition() <= vertex.first.x + vertex.second.x &&
                    y + getYPosition() >= vertex.first.y && y + getYPosition() <= vertex.first.y + vertex.second.y) ||
                    (x + getXPosition() + getWidth() >= vertex.first.x && x + getXPosition() + getWidth() <= vertex.first.x + vertex.second.x &&
                    y + getYPosition() + getHeight() >= vertex.first.y && y + getYPosition() + getHeight() <= vertex.first.y + vertex.second.y)) {
                    return;
                }
            }

            sf::Vector2f pos(x, y);
            sprite.move(pos);
        }

        //Instantly places the object to the designated coordinates
        void setPosition(float x, float y) {
            sf::Vector2f pos(x, y);
            sprite.setPosition(pos);
        }

        void setBoundary(std::vector<std::pair<sf::Vector2f, sf::Vector2f>>* bList) {
            boundaries = bList;
        }

        //Current bool movement of the object
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;

    protected:
        sf::Texture texture;
        sf::Sprite sprite;

        //Boundary where the object cannot pass through
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>>* boundaries;
};

#endif // OBJECT_H
