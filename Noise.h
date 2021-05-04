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

	float getPercent () const
	{
		return percent;
	}
	void setPercent (float newPercent)
	{
		percent = newPercent;
	}

	void processBuffer(A buffer, int bufferSize, int bit_size)
	{
		float max, min;
		if(bit_size > 255)
		{
			if (percent >= 0 && percent <= 1)
			{
				max = percent * bit_size;
				min = 0 - (percent * bit_size);
				
				for (int index = 0; index < bufferSize; index++)
				{
					if (buffer[index] >= min && buffer[index] <= max)
					{
						buffer[index] = 0;
					}
				}
			}
		}
		else
		{
			if (percent >= 0 && percent <= 1)
			{
				max = (percent * 128) + 128;
				min = 128 - (percent * 128);

				for (int index = 0; index < bufferSize; index++)
				{
					if (buffer[index] >= min && buffer[index] <= max)
					{
						buffer[index] = 128;
					}
				}
			}
		}
	}
};

#include "Noise.cpp"
#endif //NOISE_H
