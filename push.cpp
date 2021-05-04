//Author: Lauren Feldman
//Date: 4/20/21
//Group Project

#include "push.h"
int Push::getInput()
{
	return input;
}
void Push::setInput()
{
	std::cout << "Please pick an numbered option: " << std::endl;
	std::cin >> input;
}
	
void Push::printDetails(std::vector<std::string> file_names)
{
	std::cout << "These are the file available for processing" << std::endl; 
	
	for(std::vector<std::string>::iterator t = file_names.begin(); t != file_names.end(); t++)
	{	
		int count = 1;
		std::cout << "File " << count << ": " << *t << std::endl;
		count++;
	}
}

void Push::printDetails(std::vector<Subchunk*> meta_subs)
{
	for(int index = 0; index < meta_subs.size(); index++)
	{
		if(meta_subs[index]->getId() == "INAM")
		{
			std::cout << "Track TItle: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "IART")
		{
			std::cout << "Artist Name: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "IPRD")
		{
			std::cout << "Album Title: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "IGNR")
		{
			std::cout << "Genre: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "ICRD")
		{
			std::cout << "Release Year: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "ITRK")
		{
			std::cout << "Track Number: " << meta_subs[index]->getInfo() << std::endl;
		}
		else if(meta_subs[index]->getId() == "ICMT")
		{
			std::cout << "Comments: " << meta_subs[index]->getInfo() << std::endl;
		}
		else
		{
			std::cout << "There is no meta data!" << std::endl;
		}
	}
}

