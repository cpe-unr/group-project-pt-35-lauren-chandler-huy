//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef ECHO_H
#define ECHO_H

template <typename A>
class Echo
{
    int delay;

public:
    Echo(int newDelay) : delay(newDelay) {};

    int getDelay () const;
    void setDelay (int);

    void processBuffer(A buffer, int bufferSize);
};

#include "Echo.cpp"
#endif //ECHO_H
