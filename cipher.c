#include <stdio.h>
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[])
{
    make_struct("cipherprojectkey.csv");
    if (strcmp(argv[1], "e") == 0)
    {
        FILE *msgfile = fopen(argv[2], "r");
        encrypt(msgfile, argv[3]);
    }
    else if (strcmp(argv[1], "d") == 0)
    {
        FILE *encfile = fopen(argv[2], "r");
        decrypt(encfile, argv[3]);
    }
    else
    {
        printf("Usage: ./cipher ['e' (encode) / 'd' (decode)] [text file to encode/decode] [name for outfile]\n");
        return 1;
    }
    freemem();
}
