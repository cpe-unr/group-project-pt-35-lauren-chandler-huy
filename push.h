//Author: Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef PUSH_H
#define PUSH_H

#include <iostream>	
#include <vector>
#include <string>

#include "Wav.h"

class Push
{
	int input = 0;	
	
public:
	int getInput();
	void setInput();
	
	void printDetails(std::vector<std::string> file_names);
	void printDetails(std::vector<Subchunk*> meta_subs);
	
};
#endif //PUSH_H

