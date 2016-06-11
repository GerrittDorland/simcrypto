#ifndef GFCT_H
#define GFCT_H

int custlen(char* input);
char* getFT(char* input);
char rotateByteL(char byte, int numShifts);
char rotateByteR(char byte, int numShifts);

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


char* getFT(char* input)
{
  int i = 0, j = 0, k = 0;
  char* ext;

  while(input[i] != '.' && input[i] != '\0')
  {
    i++;
  }

  if(input[i] == '.')
  {
    j = i;
    while(input[j] != '\0')
    {
      j++;
    }
    j++;

    ext = (char*) malloc(j);

    j = i;

    while(input[j] != '\0')
    {
      ext[k] = input[j];
      k++;
      j++;
    }
    ext[k] = '\0';
  }
  else
  {
    ext = (char*) malloc(2);
    ext[0] = 'x';
    ext[1] = '\0';
  }
  return ext;
}

char rotateByteL(char byte, int numShifts)
{
  char carryBit, byteHold = byte;
  int i = 0;

  for(i = 0; i < numShifts; i++)
  {
    //Snag topmost bit
    carryBit = byteHold & 0x80;

    //Rotate once
    byteHold = byteHold << 1;
    byteHold = byteHold & 0xFE;

    //move the captured bit to the LSB
    carryBit = carryBit >> 7;
    carryBit = carryBit & 0x01;

    //Tack it to the end
    byteHold += carryBit;
  }
  return(byteHold);
}

char rotateByteR(char byte, int numShifts)
{
  char carryBit, byteHold = byte;
  int i = 0;

  for(i = 0; i < numShifts; i++)
  {
    //Snag topmost bit
    carryBit = byteHold & 0x01;

    //Rotate once
    byteHold = byteHold >> 1;
    byteHold = byteHold & 0x7F;

    //move the captured bit to the MSB
    carryBit = carryBit << 7;
    carryBit = carryBit & 0x80;

    //Tack it to the top
    byteHold += carryBit;
  }
  return(byteHold);
}

#endif
