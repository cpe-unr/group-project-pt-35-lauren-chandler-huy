//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project
/**
 * The main function appropriately creats and calls the proper functions within each object to process user input and select the proper wavs and processors required.
 * This main should first call the push object to print out input to the user then receive that input to open the correct file and processor.
 * The processor will then run and return a buffer that will be written 
 */
#include "Wav.h"
#include "Echo.h"
#include "Limit.h"
#include "Noise.h"
#include "push.h"

int main ()
{
	Wav wave_read;

	wave_read.readFile("yes-8bit-mono.wav");
	if (wave_read.getBits() == 16)
	{
		Echo<short>* echo = new Echo<short>(1000);
		Limiter<short>* limit = new Limiter<short>(0.8);
		NoiseGate<short>* noise = new NoiseGate<short>(0.1); 
	}
	
	wave_read.readFile("yes-8-bit-stereo.wav");
	
	wave_read.readFile("yes-16-bit-mono.wav");
	
	wave_read.readFile("yes-26-bit-stereo.wav");
	
	return 0;
}
