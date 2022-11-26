#include "ball.h"

ball::ball() {}
ball::~ball() {}

void ball::hasCollided() {
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

        float xCollision1 = thisObjectHighX - boundaryLowX;
        float xCollision2 = boundaryHighX - thisObjectLowX;
        float xCollision3 = std::min(xCollision1, xCollision2);
        bool xCollision = (xCollision1 >= 0) && (xCollision2 >= 0);

        float yCollision1 = thisObjectHighY - boundaryLowY;
        float yCollision2 = boundaryHighY - thisObjectLowY;
        float yCollision3 = std::min(yCollision1, yCollision2);
        bool yCollision = (yCollision1 >= 0) && (yCollision2 >= 0);

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
