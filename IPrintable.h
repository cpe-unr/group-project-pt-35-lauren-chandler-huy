//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include <string>
#include <vector>

#include "Subchunk.h"

class IPrintable
{
	virtual std::vector<std::string> getFiles() = 0;
	virtual std::vector<Subchunk*> getMeta() = 0;

};

#endif //IPRINTABLE_H
