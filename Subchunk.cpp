//Author: Huy Tran, Lauren Feldman
//Date: 5/2/21
//Group Project

#include "Subchunk.h"

std::string getId () const
{
	return Id;
}

void setId (std::string newId)
{
	Id = newId;
}
	
std::string getInfo () const
{
	return info;
}

void setInfo (std::string newInfo)
{
	info = newInfo;
}
	
int getSize () const
{
	return size;
}

void setSize (int newSize)
{
	size = newSize;
}
	
std::string convertArray (char* array, int length)
{
	std::string s;

	for (int c; c < length; i++)
	{
		s = s + array[i];
	}
}
