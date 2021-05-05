//Author: Huy Tran, Lauren Feldman
//Date: 5/3/21
//Group Project 

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
