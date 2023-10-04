#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc!=3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    FILE *wav_file = fopen(argv[1], "r");
    if (wav_file == NULL)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header,sizeof(WAVHEADER),1,wav_file);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header)!=0)
    {
        printf("%dInput is not a WAV file.\n",check_format(header));
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL)
    {
        printf("couldnt open output file.\n");
        return 1;
    }
    // Write header to file
    // TODO #6

    fwrite(&header,sizeof(WAVHEADER),1,out_file);

    // Use get_block_size to calculate size of block
    // TODO #7

    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8

    /*
    BYTE stuff[block_size];
    fseek(wav_file , sizeof(WAVHEADER) , SEEK_SET);
    fread(&stuff,block_size,1,wav_file);
    fseek(out_file , sizeof(WAVHEADER)  , SEEK_SET);
    BYTE reversed[block_size];

    for (int i = 0 ; i<block_size ; i++)
    {
        reversed[i] = stuff[block_size - i -1];
    }

    fwrite(&reversed, block_size , 1 , out_file);

    fclose(wav_file);
    fclose(out_file);
    */
     fseek(wav_file, block_size, SEEK_END);
    BYTE buffer[block_size];

    while (ftell(wav_file) - block_size > sizeof(header)) 
    {
        if (fseek(wav_file, -2 * block_size, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, block_size, 1, wav_file);
        fwrite(buffer, block_size, 1, out_file);
    }

    // Close files
    fclose(wav_file);
    fclose(out_file);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE WAVE[4];
    WAVE[0] = 'W';
    WAVE[1] = 'A';
    WAVE[2] = 'V';
    WAVE[3] = 'E';

    if (header.format == WAVE)
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int block_size = header.numChannels * (int) ((float) header.bitsPerSample / 8);

    return block_size;
}