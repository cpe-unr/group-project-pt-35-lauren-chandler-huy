//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#include "Wav.h"

int main ()
{
	Wav wave_read;
	wave_read.readFile("yes-8bit-mono.wav");
	wave_read.readFile("yes-8-bit-stereo.wav");
	wave_read.readFile("yes-16-bit-mono.wav");
	wave_read.readFile("yes-26-bit-stereo.wav");
	

	return 0;
}
