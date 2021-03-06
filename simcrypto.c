#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/gfct.h"
#include "headers/mainfunctionality.h"

void usage(void);

int main(int argc, char** argv)
{
  char *file, *password, *outfile;
  int encr = 0, selection = 0;
  int i;

  if(argc < 4)
  {
    usage();
  }

  else
  {
    for(i = 0; i < argc; i++)
    {
      //0 indicates equal...
      if(strcmp(argv[i],"-f") == 0)
      {
        file = (char*)malloc(custlen(argv[i+1]));
        strcpy(file, argv[i+1]);
      }
      else if(strcmp(argv[i],"-p") == 0)
      {
        password = (char*)malloc(custlen(argv[i+1]));
        strcpy(password, argv[i+1]);
      }
      else if (strcmp(argv[i],"-e") == 0 && selection == 0)
      {
        outfile = (char*)malloc(custlen(argv[i+1]));
        strcpy(outfile, argv[i+1]);
        encr = 1;
        selection = 1;
      }
      else if (strcmp(argv[i],"-d") == 0 && selection == 0)
      {
        outfile = (char*)malloc(custlen(argv[i+1]));
        strcpy(outfile, argv[i+1]);
        encr = 0;
        selection = 1;
      }
    }

    if(selection == 1)
    {
      if(encr == 1)
      {
        encrypt(file, password, outfile);
      }
      else
      {
        decrypt(file, password, outfile);
      }
    }
    else
    {
      usage();
    }
  }
  //printf("\nYO: %s %s", file, password);
}

void usage(void)
{
  printf("\n     -------\n      USAGE\n     -------\nYou fucking nonce... \
  \n   -f [filename]\n   -p [password]\n \
  -e [filename] :: Encrypt into [filename]\n \
  -d [filename] :: Decrypt into [filename]\n\n \
  EXAMPLE USAGE:\n \
  ./simcrypto -f myFile.txt -p pass123 -e encrypted\n \
  ./simcrypto -f encrypted.txt -p pass123 -d decrypted\n\n");
}
