//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

class Wav
{
protected:
	unsigned char* buffer = NULL;
	bool mono = false;
	bool stereo = false;
	wav_header waveHeader;
	fmt_header FMT;
	data_header Data;
	meta_header Meta;
	chunk_info Chunk;
	    
public:
	Wav() = default;
	
	bool getMono () const;
	void setMono (bool newMono);

	bool getStereo () const;
	void setStereo (bool newStereo);

	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);
	    
	unsigned char* getBuffer();
	int getBufferSize() const;
	
	virtual ~Wav();
};

#endif //WAV_H
