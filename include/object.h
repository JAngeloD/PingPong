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

        void setVelocity(float x, float y) {
            xVelocity = x;
            yVelocity = y;
        }

        std::pair<sf::Vector2f, sf::Vector2f> getBoundary() {
            sf::Vector2f vertex1(sprite.getPosition().x, sprite.getPosition().y);
            sf::Vector2f vertex2(texture.getSize().x, texture.getSize().y);
            return std::make_pair(vertex1, vertex2);
        }

        virtual void hasCollided(){
            //Checks if object is outside of boundary before moving
            for(std::pair<sf::Vector2f, sf::Vector2f> vertex : *boundaries) {
                /// Instantiates
                float thisObjectLowX = getXPosition() + xVelocity;
                float thisObjectHighX = thisObjectLowX + getWidth() + xVelocity;
                float thisObjectLowY = getYPosition() + yVelocity;
                float thisObjectHighY = thisObjectLowY + getHeight() + yVelocity;

                float boundaryLowX = vertex.first.x;
                float boundaryHighX = boundaryLowX + vertex.second.x;
                float boundaryLowY = vertex.first.y;
                float boundaryHighY = boundaryLowY + vertex.second.y;

                bool xCollision = ((thisObjectHighX - boundaryLowX) > 0) && ((boundaryHighX - thisObjectLowX) > 0);
                bool yCollision = ((thisObjectHighY - boundaryLowY) > 0) && ((boundaryHighY - thisObjectLowY) > 0);

                if (xCollision && yCollision) {
                    setVelocity(0,0);
                }
            }
        }

        void move() {
            hasCollided();
            sf::Vector2f pos(xVelocity, yVelocity);
            sprite.move(pos);
        }

        //Instantly places the object to the designated coordinates
        void setPosition(float x, float y) {
            sf::Vector2f pos(x, y);
            sprite.setPosition(pos);
        }

        void setBoundary(std::vector<std::pair<sf::Vector2f, sf::Vector2f>>* bList) {boundaries = bList;}

        //Current bool movement of the object
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;

    protected:
        //Holds the textures
        sf::Texture texture;
        sf::Sprite sprite;

        //Boundary where the object cannot pass through
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>>* boundaries;

        float xVelocity;
        float yVelocity;
};

#endif // OBJECT_H
