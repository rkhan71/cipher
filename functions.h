#include "definitions.h"
#include <stdio.h>

void make_struct(char *fn);

int encrypt(FILE *msgfile, char *ofn);

int decrypt(FILE *encfile, char *ofn);

void freemem(void);
