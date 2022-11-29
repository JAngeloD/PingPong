#ifndef BALL_H
#define BALL_H

#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "object.h"

class ball : public object
{
    public:
        ball();
        virtual ~ball();

        void hasCollided() override;
        void startVelocity();
        void resetPosition();

    private:
        float defaultXVelocity = 1.75f;
        float defaultYVelocity = 1.75f;
};

#endif // BALL_H
