#ifndef PADDLE_H
#define PADDLE_H

#include "object.h"

class paddle : public object
{
    public:
        paddle();
        virtual ~paddle();

        void setPlayerReset();
        void setCPUReset();

    private:
};

#endif // PADDLE_H
