#include "ball.h"

ball::ball() {}
ball::~ball() {}

void ball::moveBall() {
    //Checks if object is outside of boundary before moving
    for(std::pair<sf::Vector2f, sf::Vector2f> vertex : *boundaries) {
        if ((xVelocity + getXPosition() + getWidth() >= vertex.first.x && xVelocity + getXPosition() + getWidth() <= vertex.first.x + vertex.second.x) ||
            (xVelocity + getXPosition() >= vertex.first.x && xVelocity + getXPosition() <= vertex.first.x + vertex.second.x)) {
            xVelocity *= -1;
        }

        if ((yVelocity + getYPosition() >= vertex.first.y && yVelocity + getYPosition() <= vertex.first.y + vertex.second.y) ||
            (yVelocity+ getYPosition() + getHeight() >= vertex.first.y && yVelocity + getYPosition() + getHeight() <= vertex.first.y + vertex.second.y)) {
            yVelocity *= -1;
        }
    }

    sf::Vector2f pos(xVelocity, yVelocity);
    sprite.move(pos);
}
