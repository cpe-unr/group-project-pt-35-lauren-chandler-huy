//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

class Wav
{
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
    
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
    
    unsigned char *getBuffer();
    int getBufferSize() const;
    
    virtual ~Wav();
};


#endif //WAV_H
