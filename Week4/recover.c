#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    // Buffer to read blocks of 512 bytes
    uint8_t buffer[BLOCK_SIZE];

    // Counter for JPEG files found
    int jpeg_count = 0;

    // File pointer for the current JPEG file
    FILE *output_file = NULL;

    // Read until end of file
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // Check if it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If we have an open JPEG file, close it
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create new JPEG file
            char filename[8]; // ###.jpg plus the null terminator
            sprintf(filename, "%03d.jpg", jpeg_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fprintf(stderr, "Could not create output file %s\n", filename);
                fclose(input_file);
                return 2;
            }

            // Increment JPEG counter
            jpeg_count++;
        }

        // Write block to JPEG file if one is open
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, output_file);
        }
    }

    // Close input file
    fclose(input_file);

    // Close output file if it's open
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Success
    return 0;
}
