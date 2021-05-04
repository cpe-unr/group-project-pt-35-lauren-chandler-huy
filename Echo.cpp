//Author: Huy Tran
//Date: 3/18/21
//Programming Assignment 3

#include "Echo.h"

int Echo::getDelay () const
{
	return delay;
}

void Echo::setDelay (int newDelay)
{
	delay = newDelay;
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize)
{
	for (int count = 0; count < bufferSize; count++)
	{
		buffer[count + delay] = (buffer[count]/2) + (buffer[count + delay]/2);
	}
}
