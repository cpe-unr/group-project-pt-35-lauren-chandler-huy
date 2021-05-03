//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef LIMIT_H
#define LIMIT_H

#include "Processor.h"

class Limiter : public Processor
{
    float percentDb;

public:
    Limiter(float newPercent) : percentDb(newPercent) {};

    float getPercentDb () const;
    void setPercentDb (float);

    void processBuffer(unsigned char*, int) override;
};

#endif //LIMIT_H
