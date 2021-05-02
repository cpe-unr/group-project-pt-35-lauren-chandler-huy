#Author: Huy Tran, Lauren Feldman
#Date: 4/20/21
#Group Project

readtest: Wav.o WavMain.cpp 
	g++ -std=c++11 Wav.o WavMain.cpp -o readtest

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -c -std=c++11 Wav.cpp
	
Wav.a: Wav.o
	ar suvr Wav.a wav.o
	
Echo.o: Echo.cpp Echo.h Processor.h
	g++ -c -std=c++11 Echo.cpp

Limit.o: Limit.cpp Limit.h Processor.h
	g++ -c -std=c++11 Limit.cpp

Noise.o: Noise.cpp Noise.h Processor.h
	g++ -c -std=c++11 Noise.cpp

clean:
	rm *.o readtest
