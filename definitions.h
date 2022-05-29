// file to define constants and structure

// constants
#define BUFSIZE 10 // size of buffer used to copy key
#define KEYSIZE 96 // number of elements in key
#define MAX 500 // max number of characters for plaintext message

// create struct to put key into
typedef struct
{
    char chars;
    char *bytes;
}
keystruct;
keystruct key[KEYSIZE];
