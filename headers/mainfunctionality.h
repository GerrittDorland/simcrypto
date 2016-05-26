#ifndef MAINFUNCTIONALITY_H
#define MAINFUNCTIONALITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfct.h"

void encrypt(char* infilename)
{
  FILE *fp, *outfp;

  fp = fopen(infilename);

  fclose(fp);
}

#endif
