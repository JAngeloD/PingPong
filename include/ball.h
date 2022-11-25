#ifndef BALL_H
#define BALL_H

#include "object.h"
#include <algorithm>

class ball : public object
{
    public:
        ball();
        virtual ~ball();

        void hasCollided() override;

    private:
};

#endif // BALL_H
