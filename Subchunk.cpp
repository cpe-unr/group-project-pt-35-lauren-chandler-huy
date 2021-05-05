//Author: Huy Tran, Lauren Feldman
//Date: 5/2/21
//Group Project

#include "Subchunk.h"

std::string Subchunk::getId () const
{
	return id;
}

void Subchunk::setId (std::string newId)
{
	id = newId;
}
	
std::string Subchunk::getInfo () const
{
	return info;
}

void Subchunk::setInfo (std::string newInfo)
{
	info = newInfo;
}
	
int Subchunk::getSize () const
{
	return size;
}

void Subchunk::setSize (int newSize)
{
	size = newSize;
}
