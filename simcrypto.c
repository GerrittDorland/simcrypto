#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/gfct.h"
#include "headers/mainfunctionality.h"

void usage(void);

int main(int argc, char** argv)
{
  char *file, *password;
  int i, j, k;

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
    }
  }
  //printf("\nYO: %s %s", file, password);
}

void usage(void)
{
  printf("\n     -------\n      USAGE\n     -------\nYou fucking nonce...\n   -f [filename]\n   -p [password]\n\n");
}
