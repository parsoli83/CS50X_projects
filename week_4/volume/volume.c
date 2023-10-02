// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


long get_file_size(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp==NULL)
        return -1;

    if (fseek(fp, 0, SEEK_END) < 0) {
        fclose(fp);
        return -1;
    }

    long size = ftell(fp);
    // release the resources when not required
    fclose(fp);
    return size;
}


// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    
    uint8_t header[44];
    fread(&header,1,44,input);
    fwrite(&header,1,44,output);

    int16_t buffer;
    while (fread(&buffer, 2, 1, input)) 
    {
        buffer *= factor;
        fwrite(&buffer, 2, 1, output);
    }
    
    
        // Close files
    fclose(input);
    fclose(output);
}
