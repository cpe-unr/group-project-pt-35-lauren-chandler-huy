//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#ifndef NOISE_H
#define NOISE_H

template <typename A>
class NoiseGate
{
    float percent = 0;

public:
    NoiseGate(float newPercent) : percent(newPercent) {};

    float getPercent () const;
    void setPercent (float);

    void processBuffer(A buffer, int bufferSize) override;

};

#include "Noise.cpp"
#endif //NOISE_H
