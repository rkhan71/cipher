#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  //check that the command line arguments are there and that they work
  if (argc != 2)
  {
    printf("Usage: ./struct [txt file name]\n");
    return 1;
  }
  FILE *msgfile = fopen(argv[1], "r");
  if (msgfile == NULL)
  {
    printf("Cannot read file\n");
    return 1;
  }

  // constants
  #define BUFSIZE 10
  #define KEYSIZE 95

  // create struct to put key into
  typedef struct {
    char chars;
    char *bytes;
    }
  keystruct;
  keystruct key[KEYSIZE];

  // get key from file and fill the struct
  FILE *keyfile = fopen("decodekeynew.csv", "r");
  char buffer[BUFSIZE];
  fread(buffer, 3, 1, keyfile); // get rid of first 3 bytes in csv file
  int i = 0;
  while (fgets(buffer, BUFSIZE, keyfile) != NULL) {
    key[i].chars = buffer[0];
    char *byte = malloc(strlen(&buffer[2]) - 1);
    strncpy(byte, &buffer[2], strlen(&buffer[2]) - 2);
    key[i].bytes = byte;
    i++;
    }

  // get message from file then convert it to cipher text
  char msgchar;
  char ctext[1000]; //need to allocate memory first so there's a 500 char max for the message
  int j = 0;
  while (fread(&msgchar, 1, 1, msgfile) == 1)
  {
    for (int k = 0; k < KEYSIZE; k++)
    {
      if (msgchar == key[k].chars)
      {
        ctext[j] = *key[k].bytes;
        break;
      }
      else if (k == KEYSIZE - 1)
      {
        printf("Character from file not recognized\n"); // incase there's a character not included in key
        return 1;
      }
    }
    j += 2; // since length of byte is 2 (if length is variable use strlen to find length of byte and add that)
  }

  printf("cipher text: %s\n", ctext);
}





