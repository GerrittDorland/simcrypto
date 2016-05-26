#ifndef GFCT_H
#define GFCT_H

int custlen(char* input);

int custlen(char* input)
{
  int i = 0;

  while(input[i] != '\0')
  {
    //printf("\n---= %c", input[i]);
    i++;
  }

  i += 1;

  return i;
}

#endif
