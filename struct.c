//code that (kind of) does the basic things I want my cipher to do eventually. Essentially a plan for the overall project written in one file of code to make it simple.

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
  #define KEYSIZE 96
  #define MAX 500

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
    key[i].chars = '\n'; // manually adding in newline character
    key[i].bytes = "0a";
    fclose(keyfile);

  // get message from file then convert it to cipher text
  char msgchar;
  char ctext[MAX * 2]; //need to allocate memory first so there's a 500 char max for the message (since bytes are 2 chars in this case)
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
  printf("cipher text: %s\n", ctext);

  // convert cipher text back to plain text
  char ptext[MAX];
  for (int j = 0; j < MAX; j++)
  {
    ptext[j] = '\0';
  }
  int l = strlen(ctext);
  for (int k = 0; k < l; k += 2)
  {
    char cbyte[3] = "\0\0\0";
    strncat(cbyte, &ctext[k], 1);
    strncat(cbyte, &ctext[k + 1], 1);
    for (int j = 0; j < KEYSIZE; j++)
    {
      if (strcmp(cbyte, key[j].bytes) == 0)
      {
        strncat(ptext, &key[j].chars, 1);
        break;
      }
    }
  }
  printf("plain text: %s\n", ptext);

  //free allocated memory
  for (int j = 0; j < KEYSIZE - 1; j++)
  {
    free(key[j].bytes);
  }
}
