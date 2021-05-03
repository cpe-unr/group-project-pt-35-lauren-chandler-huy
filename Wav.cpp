//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#include <fstream>
#include <iostream>

#include "Wav.h"

bool Wav::getMono () const
{
	return mono;
}

void Wav::setMono (bool newMono)
{
	mono = newMono;
}

bool Wav::getStereo () const
{
	return stereo;
}

void Wav::setStereo (bool newStereo)
{
	stereo = newStereo;
}

void Wav::readFile(const std::string &fileName)
{
	std::ifstream file(fileName,std::ios::binary | std::ios::in);

	if(file.is_open())
	{
		file_list.emplace_back(fileName);
	
		file.read((char*)&waveHeader, sizeof(wav_header));
		
		file.read((char*)&FMT, sizeof(fmt_header));
		
		if (FMT.num_channels == 1)
		{
			setMono(true);
		}
		if (FMT.num_channels == 2)
		{
			setStereo(true);
		}
		
		file.read((char*)&Data, sizeof(data_header));
		
		buffer = new unsigned char[Data.data_bytes];
		file.read((char*)buffer, Data.data_bytes);
		
		if(FMT.bit_depth == 16);
		{
			short* shortBuffer = reinterpret_cast<short*>(buffer);
		}
		
		file.read((char*)&Meta, sizeof(meta_header));
		
		for(int i = sizeof(meta_header); i < Meta.meta_chunks; i += Chunk.sub_size)
		{
			std::string meta_hold;
			
			file.read((char*)&Chunk, sizeof(chunk_info));
			char info_holder[Chunk.sub_size];
			file.read(info_holder, Chunk.sub_size);
			
			Chunk.
		}
		file.close();
	}
	

}

unsigned char* Wav::getBuffer()
{
	return buffer;
}

void Wav::writeFile(const std::string &outFileName) 
{
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)&FMT,sizeof(fmt_header));
	outFile.write((char*)&Data, sizeof(data_header));
	outFile.write((char*)buffer, Data.data_bytes);
	outFile.close();
}

std::vector<std::string> Wav::getFiles()
{
	return file_list;
}

std::vector<std::string> Wav::getMeta()
{
	return chunk_list;
}

Wav::~Wav()
{
	if(buffer != NULL)
	delete[] buffer;
}

int Wav::getBufferSize() const
{
	return Data.data_bytes;
}
