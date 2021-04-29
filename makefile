#Author: Huy Tran, Lauren Feldman
#Date: 4/20/21
#Group Project

readtest: Wav.o WavMain.cpp 
	g++ -std=c++11 Wav.o WavMain.cpp -o readtest

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -c -std=c++11 Wav.cpp

clean:
	rm *.o readtest
