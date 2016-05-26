GCC = gcc
CFLAGS = -Wall -O2
HEADERSDIR = headers/

all: simcrypto

simcrypto: simcrypto.c $(HEADERSDIR)gfct.h $(HEADERSDIR)mainfunctionality.h
	$(GCC) $(CFLAGS) simcrypto.c -o simcrypto

clean:
	rm -rf simcrypto
