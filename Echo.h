//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"

class Echo : public Processor
{
    int delay;

public:
    Echo(int newDelay) : delay(newDelay) {};

    int getDelay () const;
    void setDelay (int);

    void processBuffer(unsigned char* buffer, int bufferSize) override;
};

#endif //ECHO_H
