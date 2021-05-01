//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project


//add and make new structs for each part so we can read that in and check it through the read in file.
//maybe consider creating a wav that is inherited by an 16bit and 8bit class. 
//ask if typecasting to a short buffer changes the data within with unsigned char.


#ifndef WAVEHEADER_H
#define WAVEHEADER_H

/*
 * https://docs.fileformat.com/audio/wav/
 * Positions	Sample Value	Description
1 - 4	“RIFF”	Marks the file as a riff file. Characters are each 1 byte long.
5 - 8	File size (integer)	Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you’d fill this in after creation.
9 -12	“WAVE”	File Type Header. For our purposes, it always equals “WAVE”.
13-16	“fmt "	Format chunk marker. Includes trailing null
17-20	16	Length of format data as listed above
21-22	1	Type of format (1 is PCM) - 2 byte integer
23-24	2	Number of Channels - 2 byte integer
25-28	44100	Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
29-32	176400	(Sample Rate * BitsPerSample * Channels) / 8.
33-34	4	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
35-36	16	Bits per sample
37-40	“data”	“data” chunk header. Marks the beginning of the data section.
41-44	File size (data)	Size of the data section.
 */
typedef struct wav_header 
{
	// RIFF Header
	char riff_header[4]; // Contains "RIFF"
	int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
	char wave_header[4]; // Contains "WAVE"

} wav_header;

typedef struct fmt_header
{
	// Format Header
	char fmt_header[4]; // Contains "fmt " (includes trailing space)
	int fmt_chunk_size; // Should be 16 for PCM
	short audio_format; // Should be 1 for PCM. 3 for IEEE Float
	short num_channels;
	int sample_rate;
	int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
	short sample_alignment; // num_channels * Bytes Per Sample
	short bit_depth; // Number of bits per sample
	
} fmt_header;

typedef struct data_header
{
	// Data
	char data_header[4]; // Contains "data"
	int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // char bytes[]; // Remainder of wave file is bytes
    
} data_header;

typedef struct meta_header
{
	char meta_header[4]; // Contains "LIST"
	int meta_chunks; // Number of bytes in metadata.
	char chunk_header[4]; // Contains "INFO"
	
	
} meta_header;
#endif //WAVEHEADER_H
