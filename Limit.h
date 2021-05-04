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

	float getPercentDb () const
	{
		return percentDb;
	}

	void setPercentDb (float newPercent)
	{
		percentDb = newPercent;
	}

	void processBuffer(A buffer, int bufferSize, int bit_size)
	{
		float highDecib, lowDecib;
		
		if(bit_size > 255)
		{
			if (percentDb >= 0 && percentDb <= 1)
			{
				highDecib = percentDb * bit_size;
				lowDecib = 0 - (percentDb * bit_size);
				
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
		else
		{
			if (percentDb >= 0 && percentDb <= 1)
			{
				highDecib = (percentDb * 128) + 128;
				lowDecib = 128 - (percentDb * 128);
				

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
	}
};

#include "Limit.cpp"
#endif //LIMIT_H
