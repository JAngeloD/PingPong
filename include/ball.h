#ifndef BALL_H
#define BALL_H

#include "object.h"

class ball : public object
{
    public:
        ball();
        virtual ~ball();

        void setVelocity(float x, float y) {
            xVelocity = x;
            yVelocity = y;
        }

        void moveBall();

    private:

        float xVelocity;
        float yVelocity;
};

#endif // BALL_H
