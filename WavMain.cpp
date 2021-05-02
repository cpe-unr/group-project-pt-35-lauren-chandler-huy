//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#include <iostream>

#include "Wav.h"
#include "WaveHeader.h"

int main ()
{
	Wav wave_test;
	wave_test.readFile("yes-8bit-mono.wav");
	wave_test.readFile("yes-8-bit-stereo.wav");
	wave_test.readFile("yes-16-bit-mono.wav");
	wave_test.readFile("yes-26-bit-stereo.wav");
	
	return 0;
}
