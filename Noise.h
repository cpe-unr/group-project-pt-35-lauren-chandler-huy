//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef NOISE_H
#define NOISE_H

#include "Processor.h"

class NoiseGate : public Processor
{
    float percent = 0;

public:
    NoiseGate(float newPercent) : percent(newPercent) {};

    float getPercent () const;
    void setPercent (float);

    void processBuffer(unsigned char* buffer, int bufferSize) override;

};

#endif //NOISE_H
