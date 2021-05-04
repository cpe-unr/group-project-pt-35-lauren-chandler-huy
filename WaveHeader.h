//Author: Huy Tran, Lauren Feldman
//Date: 4/20/21
//Group Project

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

/**
 * This is a header file that contains all the structs to properly contain the information of a wav file header
 */
typedef struct wav_header 
{
	/**
	 * This header holds "RIFF", the size of the file, and "WAVE"
	 */
	char riff_header[4]; // Contains "RIFF"
	int wav_size; // The size of the file in bytes
	char wave_header[4]; // Contains "WAVE"

} wav_header;

typedef struct fmt_header
{
	/**
	 * Header holds "fmt " and the technical data of the wav file
	 */
	char fmt_head[4]; // Contains "fmt " (includes trailing space)
	int fmt_chunk_size; // Should be 16 for PCM
	short audio_format; // Should be 1 for PCM. 3 for IEEE Float
	short num_channels; // Should be 1 for Mono, 2 for Stereo
	int sample_rate;
	int byte_rate; // Number of bytes per second
	short sample_alignment;
	short bit_depth; // Number of bits per sample
	
} fmt_header;

typedef struct data_header
{
	/**
	 * Holds "data" and the amount of data in bytes
	 */
	char data_head[4]; // Contains "data"
	int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    
} data_header;

typedef struct meta_header
{
	/**
	 * Holds "LIST", number of bytes in metadata, and "INFO"
	 */
	char meta_head[4]; // Contains "LIST"
	int meta_chunks; // Number of bytes in metadata.
	char chunk_header[4]; // Contains "INFO"
	
} meta_header;

typedef struct chunk_info
{
	/**
	 * Contains ID Of subchunk in metadata, and number of characters in the data
	 */
	char sub_header[4]; // Contains ID of subchunk
	int sub_size; // Number of characters in chunk data
	
} chunk_info;
#endif //WAVEHEADER_H
