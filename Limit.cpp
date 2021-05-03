//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#include "Limit.h"

float Limiter::getPercentDb () const
{
	return percentDb;
}

void Limiter::setPercentDb (float newPercent)
{
	percentDb = newPercent;
}

void Limiter::processBuffer(unsigned char* buffer, int bufferSize)
{
	float highDecib, lowDecib;
	highDecib = (percentDb * 128) + 128;
	lowDecib = 128 - (percentDb * 128);

	if (percentDb >= 0 && percentDb <= 1)
	{
		for (int i = 0; i < bufferSize; i++)
		{
			if (buffer[i] > highDecib)
			{
				buffer[i] = highDecib;
			}
			if (buffer[i] < lowDecib)
			{
				buffer[i] = lowDecib;
			}
		}
	}
}

