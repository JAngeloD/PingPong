#include "ball.h"
#include "engine.h"

ball::ball() {}
ball::~ball() {}

void ball::hasCollided() {
    //Checks if object is outside of boundary before moving
    for(std::pair<sf::Vector2f, sf::Vector2f> vertex : *boundaries) {
        // Gets the balls 4 vertexes (game only deals with rectangles)
        float thisObjectLowX = getXPosition() + xVelocity;
        float thisObjectHighX = thisObjectLowX + getWidth() + xVelocity;
        float thisObjectLowY = getYPosition() + yVelocity;
        float thisObjectHighY = thisObjectLowY + getHeight() + yVelocity;

        // Gets the vertexes of the potential object that will be collided with
        float boundaryLowX = vertex.first.x;
        float boundaryHighX = boundaryLowX + vertex.second.x;
        float boundaryLowY = vertex.first.y;
        float boundaryHighY = boundaryLowY + vertex.second.y;

        //Checks if the ball is in the boundary of the object to be collided with in the x and y axis
        float xCollision1 = thisObjectHighX - boundaryLowX;
        float xCollision2 = boundaryHighX - thisObjectLowX;
        float xCollision3 = std::min(xCollision1, xCollision2);
        bool xCollision = (xCollision1 >= 0) && (xCollision2 >= 0);

        float yCollision1 = thisObjectHighY - boundaryLowY;
        float yCollision2 = boundaryHighY - thisObjectLowY;
        float yCollision3 = std::min(yCollision1, yCollision2);
        bool yCollision = (yCollision1 >= 0) && (yCollision2 >= 0);

        //Checks if the collision has occured and reverses the current it's going based on what side it was collided with
        if (xCollision && yCollision) {
            if(xCollision3 >= yCollision3) {
                yVelocity *= -1;
            }
            if(xCollision3 <= yCollision3) {
                xVelocity *= -1;
            }
        }
    }
}

void ball::startVelocity() {
    defaultXVelocity *= ((std::rand() % 2 == 0) ? 1 : -1);
    defaultYVelocity *= ((std::rand() % 2 == 0) ? 1 : -1);
    setVelocity(defaultXVelocity, defaultYVelocity);
}

void ball::resetPosition() {
    setPosition((engine::xRes / 2) - (texture.getSize().x / 2), (engine::yRes / 2) - (texture.getSize().y / 2));
}
