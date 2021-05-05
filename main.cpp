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
#include "Normal.h"
#include "Noise.h"
#include "push.h"

int main ()
{
	Wav wave_read;	
	
	wave_read.readFile("yes-8bit-mono.wav");
	if (wave_read.getBits() == 16)
	{
		Echo<short*>* echo = new Echo<short*>(1000);
		Normal<short*>* normal = new Normal<short*>(0.8);
		NoiseGate<short*>* noise = new NoiseGate<short*>(0.1); 
	}
	else
	{
		Echo<unsigned char*>* echo = new Echo<unsigned char*>(1000);
		Normal<unsigned char*>* normal = new Normal<unsigned char*>(0.8);
		NoiseGate<unsigned char*>* noise = new NoiseGate<unsigned char*>(0.1);
	}
	
	wave_read.readFile("yes-8-bit-stereo.wav");
	if (wave_read.getBits() == 16)
	{
		Echo<short*>* echo = new Echo<short*>(1000);
		Normal<short*>* normal = new Normal<short*>(0.8);
		NoiseGate<short*>* noise = new NoiseGate<short*>(0.1); 
	}
	else
	{
		Echo<unsigned char*>* echo = new Echo<unsigned char*>(1000);
		Normal<unsigned char*>* normal = new Normal<unsigned char*>(0.8);
		NoiseGate<unsigned char*>* noise = new NoiseGate<unsigned char*>(0.1);
	}
	
	wave_read.readFile("yes-16-bit-mono.wav");
	if (wave_read.getBits() == 16)
	{
		Echo<short*>* echo = new Echo<short*>(1000);
		Normal<short*>* normal = new Normal<short*>(0.8);
		NoiseGate<short*>* noise = new NoiseGate<short*>(0.1); 
	}
	else
	{
		Echo<unsigned char*>* echo = new Echo<unsigned char*>(1000);
		Normal<unsigned char*>* normal = new Normal<unsigned char*>(0.8);
		NoiseGate<unsigned char*>* noise = new NoiseGate<unsigned char*>(0.1);
	}
	
	wave_read.readFile("yes-26-bit-stereo.wav");
	if (wave_read.getBits() == 16)
	{
		Echo<short*>* echo = new Echo<short*>(1000);
		Normal<short*>* normal = new Normal<short*>(0.8);
		NoiseGate<short*>* noise = new NoiseGate<short*>(0.1); 
	}
	else
	{
		Echo<unsigned char*>* echo = new Echo<unsigned char*>(1000);
		Normal<unsigned char*>* normal = new Normal<unsigned char*>(0.8);
		NoiseGate<unsigned char*>* noise = new NoiseGate<unsigned char*>(0.1);
	}
	
	return 0;
}
