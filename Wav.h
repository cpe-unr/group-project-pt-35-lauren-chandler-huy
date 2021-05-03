//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef WAV_H
#define WAV_H

#include <vector>
#include <string>

#include "WaveHeader.h"
#include "IPrintable.h"
#include "Subchunk.h"

class Wav : public IPrintable
{
protected:
	unsigned char* buffer = NULL;
	
	std::vector<std::string> file_list;
	std::vector<std::string> chunk_list;

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
	
	std::vector<std::string> getFiles() override;
	std::vector<std::string> getMeta() override;
	
	virtual ~Wav();
};

#endif //WAV_H
