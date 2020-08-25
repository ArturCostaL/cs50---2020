#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("It's required only one argument\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (argv[1] == NULL)
    {
        return 1;
    }

    BYTE bytes[512];
    int jpg_count = 0;
    bool first_jpg_found = false;
    FILE *img = NULL;

    char jpg_name[8];

    while (fread(bytes, 512, 1, file))
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            first_jpg_found = true;
            jpg_count += 1;
            if (jpg_count == 1)
            {
                sprintf(jpg_name, "%03i.jpg", jpg_count - 1);
                img = fopen(jpg_name, "w");
            }
            else if (jpg_count > 1)
            {
                fclose(img);
                sprintf(jpg_name, "%03i.jpg", jpg_count - 1);
                img = fopen(jpg_name, "w");
            }
        }
        if (first_jpg_found)
        {
            fwrite(bytes, 512, 1, img);
        }
    }
    fclose(img);




}
