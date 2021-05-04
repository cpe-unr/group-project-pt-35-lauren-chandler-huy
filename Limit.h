//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef LIMIT_H
#define LIMIT_H

template <typename A>
class Limiter
{
    float percentDb;

public:
    Limiter(float newPercent) : percentDb(newPercent) {};

    float getPercentDb () const;
    void setPercentDb (float);

    void processBuffer(A buffer, int buffer_size);
};

#include "Limit.cpp"
#endif //LIMIT_H
