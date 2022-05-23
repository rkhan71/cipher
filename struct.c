#include <stdio.h>

int main(void)
{
  typedef struct {
    char chars
    char *bytes
    }
  key;
  FILE *file = fopen("decodekeynew.csv", "r");
  char buffer[1024];
  fgets(buffer, 1024, file);
  int i = 0;
  while (fgets(buffer, 1024, file) != NULL) {
    key[i].chars = buffer[0];
    int j = 2;
    char *byte = "";
    char *bit = buffer[j];
    while (strcmp(bit, "\n") != 0) {
      byte = strcat(byte, bit);
      j++;
      bit = buffer[j];
      }
    key[i].bytes = byte;
    i++;
    }
      
    
    
  
  
  
