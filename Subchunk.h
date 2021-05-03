//Author: Huy Tran, Lauren Feldman
//Date: 5/2/21
//Group Project

#ifndef SUBCHUNK_H
#define SUBCHUNK_H

#include <string>

class Subchunk
{
protected:
	std::string Id, info;
	int size;
	    
public:
	Subchunk() = default;
	
	std::string getId () const;
	void setId (std::string newId);
	
	std::string getInfo () const;
	void setInfo (std::string newInfo);
	
	int getSize () const;
	void setSize (int newSize);
	
	std::string convertArray (char* array, int length);
};

#endif //SUBCHUNK_H
