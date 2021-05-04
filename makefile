#Author: Huy Tran, Lauren Feldman
#Date: 4/20/21
#Group Project

WaveReader: Wav.o Subchunk.o main.cpp 
	g++ -std=c++11 Wav.o Subchunk.o main.cpp -o WaveReader
	
Subchunk.o: Subchunk.cpp Subchunk.h
	g++ -c -std=c++11 Subchunk.cpp

Wav.o: Wav.cpp Wav.h WaveHeader.h IPrintable.h Subchunk.h
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
	rm *.o WaveReader
