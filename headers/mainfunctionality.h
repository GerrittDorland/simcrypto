#ifndef MAINFUNCTIONALITY_H
#define MAINFUNCTIONALITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfct.h"

void encodePass(char* inPass)
{
  int i = 0, j = custlen(inPass);
  int digitCheck = 0;

  for( i = 0; i <= j; i++)
  {
    inPass[i] = inPass[i] + inPass[j];
    digitCheck = inPass[i] - '0';
    if(digitCheck % 8 == 0)
    {
      digitCheck -= 1;
    }

    j -= 1;
  }
}

void encrypt(char* infilename, char* pass)
{
  FILE *fp, *outfp;
  char extension[10];
  char outfilename[250];
  char c, r;

  //Control vars
  char passwordTranslate;
  int passwordCharVal, i = 0;

  strcpy(extension, getFT(infilename));
  strcpy(outfilename, "outfile");
  strcat(outfilename, extension);

  fp = fopen(infilename, "r");
  outfp = fopen(outfilename, "w+");

  encodePass(pass);

  c = fgetc(fp);
  while(!feof(fp))
  {
    c += 3;

    if(pass[i] == '\0')
    {
      i = 0;
    }

    passwordTranslate = pass[i];
    passwordCharVal = pass[i] - '0';

    //passwordCharVal = passwordCharVal / 10;

    r = rotateByteL(c, passwordCharVal);

    fprintf(outfp, "%c", r);
    c = fgetc(fp);
    i++;
  }

  printf("\nTest:\n%s\n\n", extension);

  fclose(fp);
  fclose(outfp);
}

void decrypt(char* infilename, char* pass)
{
  FILE *fp, *outfp;
  char extension[10];
  char outfilename[250];
  unsigned char c, r;

  //Control vars
  char passwordTranslate;
  int passwordCharVal, i = 0;

  strcpy(extension, getFT(infilename));
  strcpy(outfilename, "outfileDecrypted");
  strcat(outfilename, extension);

  fp = fopen(infilename, "r");
  outfp = fopen(outfilename, "w+");

  encodePass(pass);

  c = fgetc(fp);
  while(!feof(fp))
  {
    if(pass[i] == '\0')
    {
      i = 0;
    }

    passwordTranslate = pass[i];
    passwordCharVal = pass[i] - '0';

    //passwordCharVal = passwordCharVal / 10;

    r = rotateByteR(c, passwordCharVal);

    r -= 3;
    fprintf(outfp, "%c", r);

    c = fgetc(fp);
    i++;
  }

  printf("\nTest:\n%s\n\n", extension);

  fclose(fp);
  fclose(outfp);
}

#endif
