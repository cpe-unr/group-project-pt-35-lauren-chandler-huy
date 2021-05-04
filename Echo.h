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

	int getDelay () const
	{
		return delay;
	}

	void setDelay (int newDelay)
	{
		delay = newDelay;
	}

	void processBuffer(A buffer, int bufferSize, bool stereo)
	{
		if(stereo)
		{
			for (int count = 0; count < bufferSize; count+=2)
			{
				buffer[count + delay] = (buffer[count]/2) + (buffer[count + delay]/2);
			}
			for (int count = 1; count < bufferSize; count+=2)
			{
				buffer[count + delay] = (buffer[count]/2) + (buffer[count + delay]/2);
			}
		}
		else
		{
			for (int count = 0; count < bufferSize; count++)
			{
				buffer[count + delay] = (buffer[count]/2) + (buffer[count + delay]/2);
			}
		}
	}

};

#include "Echo.cpp"
#endif //ECHO_H
