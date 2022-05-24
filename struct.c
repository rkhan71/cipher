#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  // create struct to put key into
  typedef struct {
    char chars;
    char *bytes;
    }
  keystruct;
  keystruct key[95];

  // get key from file and fill the struct
  FILE *file = fopen("decodekeynew.csv", "r");
  char buffer[1024];
  fgets(buffer, 1024, file);
  int i = 0;
  while (fgets(buffer, 1024, file) != NULL) {
    key[i].chars = buffer[0];
    char *byte = malloc(strlen(&buffer[2]));
    strncpy(byte, &buffer[2], strlen(&buffer[2]) - 2);
    key[i].bytes = byte;
    i++;
    }

  // get message from file? then convert it to cipher text
}

      
    
    
  
  
  
