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
	/**
	 * This is the buffer that will contain the audio data for the wav files
	 */
	unsigned char* buffer = NULL;
	/**
	 * This vector holds the names of the files that will be processed
	 */
	std::vector<std::string> file_list;
	/** 
	 * This vector holds Subchunk pointers that point to subchunks on the heap that constant the meta data information
	 */
	std::vector<Subchunk*> chunk_list;
	/**
	 * These two booleans are set when based on the wav file's number of channels
	 */
	bool mono = false;
	bool stereo = false;
	/**
	 * This attributes holds the bit_depth of the file
	 */
	int bits = 0;
	/**
	 * These are structs from the WaveHeader.h file to hold information read in
	 */
	wav_header waveHeader;
	fmt_header FMT;
	data_header Data;
	meta_header Meta;
	chunk_info Chunk;
	
public:
	/**
	 * This is the default constructor for the Wav class
	 */
	Wav() = default;

	bool getMono () const;
	void setMono (bool newMono);

	bool getStereo () const;
	void setStereo (bool newStereo);
	
	int getBits () const;
	void setBits (int newBits);
	/**
	 * Opens the file and reads in the information
	 * @param fileName - a string that contains the name of the file to read in
	 */
	void readFile(const std::string &fileName);
	/**
	 * Opens the file or creates a new file and writes in information
	 * @param outFileName - a string that contains the name of the file to write in
	 */
	void writeFile(const std::string &outFileName);
	/**
	 * Returns the unsigned buffer of data
	 */
	unsigned char* getBuffer();
	/**
	 * Returns the short casted version of the buffer
	 */
	short* getShortBuffer();
	/**
	 * Gets the size of the buffer based on bit depth
	 */
	int getBufferSize() const;
	/**
	 * From IPrintable.h which is an interface to transfer information about file names and metadata
	 */
	std::vector<std::string> getFiles() override;
	std::vector<Subchunk*> getMeta() override;
	/**
	 * The default constructor for the Wav class
	 */
	virtual ~Wav();
};

#endif //WAV_H
