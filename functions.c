// code for all the functions that will be used in the "main" code in cipher.c

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to load key from file into struct
void make_struct(char *fn)
{
    FILE *keyfile = fopen(fn, "r");
    char buffer[BUFSIZE];
    fread(buffer, 3, 1, keyfile); // get rid of first 3 bytes in csv file (for some reason they're not the actual data in file)
    int i = 0;
    while (fgets(buffer, BUFSIZE, keyfile) != NULL)
    {
        key[i].chars = buffer[0];
        char *byte = malloc(strlen(&buffer[2]) - 1);
        strncpy(byte, &buffer[2], strlen(&buffer[2]) - 2);
        key[i].bytes = byte;
        i++;
    }
    key[i].chars = '\n'; // manually adding in newline character
    key[i].bytes = "0a";
    fclose(keyfile);
}

// function to encrypt message using key and print encrypted message and write it to outfile
int encrypt(FILE *msgfile, char *ofn)
{
    char msgchar;
    char ctext[MAX * 2]; // need to allocate memory first, MAX * 2 since bytes are 2 chars in this case
    for (int j = 0; j < MAX * 2; j++)
    {
        ctext[j] = '\0';
    }
    while (fread(&msgchar, 1, 1, msgfile) == 1)
    {
        for (int k = 0; k < KEYSIZE; k++)
        {
            if (msgchar == key[k].chars)
            {
                strcat(ctext, key[k].bytes);
                break;
            }
            else if (k == KEYSIZE - 1)
            {
                printf("Character from file not recognized\n"); // incase there's a character not included in key
                return 1;
            }
        }
    }
    fclose(msgfile);
    FILE *out = fopen(ofn, "w");
    int l = strlen(ctext);
    fwrite(ctext, 1, l, out);
    printf("Cipher Text: %s\n", ctext);
    return 0;
}

// function to decrypt message using and print decrypted message and write it to outfile
int decrypt(FILE *encfile, char *ofn)
{
    char ptext[MAX];
    for (int j = 0; j < MAX * 2; j++)
    {
        ptext[j] = '\0';
    }
    char cbyte[3];
    while (fread(cbyte, 1, 2, encfile) == 1)
    {
        for (int k = 0; k < KEYSIZE; k++)
        {
            if (strcmp(cbyte, key[k].bytes) == 0)
            {
                strncat(ptext, &key[k].chars, 1); // WHAT IS THIS ABOUT I DON'T EVEN KNOW
                break;
            }
            else if (k == KEYSIZE - 1)
            {
                printf("Byte from file not recognized\n"); // incase there's a byte not included in key
                return 1;
            }
        }
    }
    fclose(encfile);
    FILE *out = fopen(ofn, "w");
    int l = strlen(ptext);
    fwrite(ptext, 1, l, out);
    printf("Plain Text: %s\n", ptext);
    return 0;
}

// function to free allocated memory
void freemem(void)
{
    for (int j = 0; j < KEYSIZE - 1; j++)
    {
        free(key[j].bytes);
    }
}
