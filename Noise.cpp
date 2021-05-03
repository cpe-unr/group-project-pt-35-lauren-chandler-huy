//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#include "Noise.h"

float NoiseGate::getPercent () const
{
	return percent;
}
void NoiseGate::setPercent (float newPercent)
{
	percent = newPercent;
}

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize)
{
	float max, min;
	max = (percent * 128) + 128;
	min = 128 - (percent * 128);

	if (percent >= 0 && percent <= 1)
	{
		for (int index = 0; index < bufferSize; index++)
		{
			if (buffer[index] >= min && buffer[index] <= max)
			{
				buffer[index] = 128;
			}
		}
	}
}
